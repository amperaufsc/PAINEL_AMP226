#include <gui/modoprova_screen/ModoProvaView.hpp>

ModoProvaView::ModoProvaView()
{
    // Construtor vazio
}

void ModoProvaView::setupScreen()
{
    ModoProvaViewBase::setupScreen();
}

void ModoProvaView::tearDownScreen()
{
    ModoProvaViewBase::tearDownScreen();
}

void ModoProvaView::updateRPMValue(int val)
{
    tacografo.setValue(val);
    tacografo.invalidate();

    Unicode::snprintf(RPM_unBuffer, RPM_UN_SIZE, "%d", val);
    RPM_un.invalidate();
}
void ModoProvaView::updateSpeedValue(int val) {
    velocimetro.setValue(val);
    velocimetro.invalidate();

    Unicode::snprintf(velocidade_unBuffer, VELOCIDADE_UN_SIZE, "%d", val);
    velocidade_un.invalidate();
}
void ModoProvaView::updateSOC(int val)
{
    // 1. Atualiza a Image Progress (bateria)
    // O setValue geralmente espera 0-100 ou o range definido no Designer
    bateria.setValue(val);

    // 2. Atualiza o número (bateria_un)
    // Se bateria_un for um TextArea com Wildcard:
    Unicode::snprintf(bateria_unBuffer, BATERIA_UN_SIZE, "%d", val);
    bateria_un.invalidate(); // Força a tela a redesenhar o texto

    // 3. Redesenha a barra de progresso
    bateria.invalidate();
}
void ModoProvaView::updateFreio(int val)
{
    freio_bar.setValue(val);
    Unicode::snprintf(freio_unBuffer, FREIO_UN_SIZE, "%d", val);
    freio_bar.invalidate();
    freio_un.invalidate();
}

void ModoProvaView::updateAcelerador(int val)
{
    Acelarador_bar.setValue(val);
    Unicode::snprintf(acelerador_unBuffer, ACELERADOR_UN_SIZE, "%d", val);
    Acelarador_bar.invalidate();
    acelerador_un.invalidate();
}
void ModoProvaView::updateTensaoHV(int val) {
    Unicode::snprintf(TensaoHV_unBuffer, TENSAOHV_UN_SIZE, "%d", val);
    TensaoHV_un.invalidate();
}

void ModoProvaView::updateDistancia(int val) {
    Unicode::snprintf(distancia_unBuffer, DISTANCIA_UN_SIZE, "%d", val);
    distancia_un.invalidate();
}

void ModoProvaView::updatePotencia(int val) {
    Unicode::snprintf(Potencia_unBuffer, POTENCIA_UN_SIZE, "%d", val);
    Potencia_un.invalidate();
}

void ModoProvaView::updateTempAcumulador(int val) {
    Unicode::snprintf(TempAcumulador_unBuffer, TEMPACUMULADOR_UN_SIZE, "%d", val);
    TempAcumulador_un.invalidate();
}
