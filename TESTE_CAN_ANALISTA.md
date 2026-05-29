# Painel AMP226 — Teste CAN no carro

Documento de instruções para o analista que vai validar o firmware do painel em bancada/carro depois das mudanças do dia 2026-05-29.

## Contexto rápido

O painel STM32U5G9J-DK2 não estava recebendo nada do barramento CAN e o firmware travava após alguns segundos. Diagnóstico: estava em `FDCAN_MODE_INTERNAL_LOOPBACK` (modo de teste, sem usar os pinos físicos) e não tratava bus-off. Já foi corrigido. Agora precisa testar no carro real.

## O que mudou no firmware

- `MX_FDCAN1_Init`: modo `INTERNAL_LOOPBACK` → `NORMAL`. SJW de 1 → 4.
- `USER CODE 2` do main: adicionado `HAL_FDCAN_ConfigGlobalFilter` (rejeita IDs estendidos — Ampera é só J1939 std) e ampliadas as notificações: `RX_FIFO0_NEW_MESSAGE | RX_FIFO0_MESSAGE_LOST | BUS_OFF | ERROR_PASSIVE | ERROR_WARNING`.
- Novo `HAL_FDCAN_ErrorStatusCallback` no main: em bus-off seta `flag_can_recovery = 1`.
- `Task_CAN` (app_freertos): no início de cada iteração checa `flag_can_recovery`. Se setado, faz `HAL_FDCAN_Stop → Start → ActivateNotification` e zera o flag. Recovery roda no contexto da task, não na ISR.
- `HAL_FDCAN_RxFifo0Callback`: agora drena o FIFO inteiro em loop (`while RxFifoFillLevel > 0`) por IRQ. Antes consumia 1 msg por IRQ, podia perder frames quando 2+ chegavam quase juntos.

Nada mais foi mexido. O fluxo TouchGFX (Model::tick → Presenter → View) está igual.

## Setup necessário

- Painel AMP226 plugado no chicote CAN do carro (J1939, 500 kbit/s).
- Pelo menos um nó ativo no barramento para gerar ACK (BMS ou VCU bastam).
- Resistor de terminação 120 Ω em cada ponta — medindo CAN_H↔CAN_L com tudo desenergizado deve dar ~60 Ω.
- STM32CubeIDE com debugger conectado (ST-Link). Pra usar os contadores precisa estar em modo debug, não só running.
- Idealmente, um analisador de barramento (PCAN, Vector ou CANalyzer) plugado em paralelo para confirmar o tráfego real.

## Procedimento de teste

### Passo 1 — Compilar e gravar

1. Abre o projeto `PAINEL_CODIGO` no STM32CubeIDE.
2. Clean + Build.
3. Grava no painel (Debug ou Run).

### Passo 2 — Sanity check sozinho na bancada

Antes de plugar no carro:

1. Liga o painel sozinho (sem outros nós CAN). Deixa rodar uns 10 segundos.
2. Para o debug e olha os contadores (próxima seção).
3. **Esperado**: `can_bus_off_count` deve subir (sem ACK → bus-off é esperado), `flag_can_recovery` ciclando, painel deve continuar respondendo (tela viva, animações ok). Se a tela trava, alguma coisa do recovery quebrou — não vai pro carro.

### Passo 3 — Teste com o carro

1. Conecta o painel no chicote CAN do carro.
2. Liga ignição (BMS+VCU ativos, telemetria circulando).
3. Deixa rodar pelo menos 5 minutos.
4. Verifica visualmente: SOC, RPM, tensão HV, temperaturas devem estar batendo com a realidade na tela ModoProva.
5. Pressiona o botão RTD físico (PA8) e confirma que a mensagem `0x141` chega no resto do barramento (precisa do analisador pra confirmar).
6. Navega entre as telas e confirma que `0x54B` muda valor (cada tela manda o seu ID).
7. Aciona o START AUTONOMOS pela UI e confirma `0x347` no barramento.

### Passo 4 — Coleta de contadores

Para no debug depois dos 5 min e anota os valores da tabela abaixo. Manda essa tabela preenchida pra mim.

## Contadores de diagnóstico (anotar no debug)

Todos são `volatile` então o debugger lê em tempo real.

| Variável | Arquivo | O que indica | Esperado pós 5min no carro |
|---|---|---|---|
| `can_recepcoes_count` | app_freertos.c | Total de frames CAN lidos com sucesso | Centenas/milhares (depende da carga do bus) |
| `model_recebeu_fila` | Model.cpp | Frames consumidos pelo GUI | Próximo de `can_recepcoes_count` |
| `debug_id_isr` | app_freertos.c | Último ID que entrou na fila | 0x120, 0x121, 0x220, 0x420 ou 0x421 |
| `ultimo_id_intruso` | Model.cpp | Último ID sem case no switch | Pode ter (frames J1939 que o painel ignora) |
| `id_errado_count` | Model.cpp | Quantos IDs caíram no default | OK se baixo/proporcional |
| `erro_fila_count` | app_freertos.c | Fila RTOS encheu (GUI lento) | **deve ser 0** ou muito baixo |
| `can_msg_lost_count` | app_freertos.c | FIFO de HW encheu | **deve ser 0** ou muito baixo |
| `debug` | app_freertos.c | `HAL_FDCAN_GetRxMessage` falhou | **deve ser 0** |
| `can_bus_off_count` | main.c | Quantos bus-off ocorreram | 0 no carro funcionando. >0 indica problema físico |
| `can_error_passive_count` | main.c | Vezes que entrou em error passive | 0 idealmente |
| `can_error_warning_count` | main.c | Vezes que TEC/REC ≥ 96 | 0 idealmente |

## Cenários e como interpretar

### Cenário A — Tudo OK
- `can_recepcoes_count` sobe, `model_recebeu_fila` acompanha.
- Tela atualiza com valores reais.
- Todos os contadores de erro em 0 ou ~0.
- **Conclusão**: firmware aprovado pro uso.

### Cenário B — Não recebe nada (`can_recepcoes_count = 0`)
- Confere se o transceiver do painel tem alimentação correta.
- Mede CAN_H↔CAN_L com multímetro (~60 Ω com tudo desligado).
- Mede CAN_H↔GND e CAN_L↔GND com osciloscópio: deve ter sinais diferenciais ~2.5V±1V.
- Confere se PA11/PA12 do MCU estão conectados ao transceiver.
- **Não é mais o firmware** — o modo já está NORMAL. Problema é HW/cabo.

### Cenário C — Recebe mas trava depois de um tempo
- Verifica se `can_bus_off_count` está subindo. Se sim, recovery não está conseguindo se sustentar.
- Verifica se o GUI continua viva (animação, toque responde). Se a UI freezou mas CAN continua, é problema no TouchGFX (não no CAN).
- Anota qual valor parou de atualizar primeiro (RPM, SOC, etc.) — ajuda a isolar.

### Cenário D — `can_msg_lost_count > 0` consistente
- FIFO de hardware (3 slots padrão) está pequeno demais pra carga do bus.
- Solução: aumentar `RxFifo0ElmtsNbr` no IOC do CubeMX (sugestão: 16). Mas isso eu (Guilherme) preciso fazer pelo Cube, não é coisa pra mexer direto no main.c. Avisa.

### Cenário E — `can_bus_off_count` sobe sozinho mesmo com BMS+VCU no bus
- Algum problema de timing no bus (baudrate divergente em algum nó).
- Confere com analisador a taxa real do barramento (500 kbit/s exato).
- Mede com osciloscópio a duração de 1 bit (~2 µs em 500k).

### Cenário F — Tela "trava" valores antigos mas o restante da UI continua viva
- Confere `model_recebeu_fila`. Se NÃO está subindo → o `Model::tick` parou de drenar a fila (provavelmente HardFault silencioso ou listener NULL). Acessa Debug → Suspend → olha onde parou.
- Se ESTÁ subindo mas tela não atualiza → bug no Presenter/View, não no CAN.

## Como reportar

Manda pra mim:

1. Tabela de contadores preenchida.
2. Duração do teste em minutos.
3. Quais valores na tela bateram com a realidade e quais não.
4. Print/foto da tela ModoProva com o carro ligado, se possível.
5. Log do analisador CAN (se tiver), pelo menos uns 30s representativos.
6. Se travou: descreve o estado da UI (congelada, animação parada, toque responde, etc) e em quanto tempo aproximado aconteceu.

Sem isso eu não consigo diagnosticar à distância. Qualquer dúvida na hora do teste me chama.

— Guilherme
