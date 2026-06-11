//AQUI É GALO
#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include <stdbool.h>
#include <stdint.h>
#include "cmsis_os2.h"
#include "can_types.h"
#include <cstring>

//so pra compilar
int msg_recebida;

Model::Model() :
		modelListener(0)
{

}

void Model::tick()
{

//            switch (msg_recebida)
//            {
//            case 0x120: { // falhas validado
//            				uint8_t falha_INVERTER = msg_recebida.data[0];
//            				uint8_t readtodrive = msg_recebida.data[3];
//            			    uint8_t falha_TMS = msg_recebida.data[4];
//                            uint16_t falha_ECU = ((uint16_t)msg_recebida.data[1] << 8) | msg_recebida.data[2];
//                            if (readtodrive == 3) {  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
//                            } else { HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);}
//
//							modelListener->RTDativo(readtodrive);
//                            modelListener->updateFalhaTMSValue(falha_TMS);
//                            modelListener->updateFalhaECUValue(falha_ECU);
//                            modelListener->updateFalhaINVValue(falha_INVERTER);
//
//                            break;
//                         }
//            case 0x121: {	//funciona mensagens 1 byte
//            				uint8_t tensCelMin = msg_recebida.data[0];
//            				uint8_t soc = msg_recebida.data[3];
//            				uint8_t acelerador = msg_recebida.data[4];
//                            uint8_t freio = msg_recebida.data[5];
//                            uint8_t TempAcumulador = msg_recebida.data[7];
//
//                            modelListener->updateTensaoCelulaMinValue(tensCelMin);
//                            modelListener->updateSOCValue(soc);
//                            modelListener->updateFreioValue(freio);
//                            modelListener->updateAceleradorValue(acelerador);
//                            modelListener->updateTempAcumuladorValue(TempAcumulador);
//                            break;
//                        }
//
//            case 0x220: { //validado
//                            float correnteHV_float = 0.0f; //acumulador
//
//                            memcpy(&correnteHV_float, &msg_recebida.data[4], sizeof(float));
//
//                            modelListener->updateCorrenteAcumuladorValue((float)correnteHV_float);
//                            break;
//                        }
//
//            case 0x420: {	//funciona mensagens 2bytes
//                            uint16_t rpm = ((uint16_t)msg_recebida.data[0] << 8) | msg_recebida.data[1];
//                            uint16_t TempMotor = ((uint16_t)msg_recebida.data[2] << 8) | msg_recebida.data[3];
//                            uint16_t TempInversor = ((uint16_t)msg_recebida.data[6] << 8) | msg_recebida.data[7];
//
//                            modelListener->updateRPMValue(rpm);
//                            modelListener->updateTempMotorValue(TempMotor);
//                            modelListener->updateTempInversorValue(TempInversor);
//                            break;
//                        }
//
//            case 0x421: {	// funciona
//                            float tensaoInversor_float = 0.0f; //trifasico
//                            float tensaoHV_float = 0.0f; //acumulador
//
//                            memcpy(&tensaoInversor_float, &msg_recebida.data[0], sizeof(float));
//                            memcpy(&tensaoHV_float, &msg_recebida.data[4], sizeof(float));
//
//                            modelListener->updateTensaoHVValue((float)tensaoHV_float);
//                            modelListener->updateTensaoInversorValue((float)tensaoInversor_float);
//                            break;
//                        }
//
//
////                case 0x000: { //velocidade e distancia SA vai mandar pra mim olhar com o carlos ou pedro quando ficar pronto
//
////                    float RodaDianteiraEsq = 0.0f;
////                    float RodaDianteiraDir = 0.0f;
//
////					  memcpy(&RodaDianteiraEsq, &msg_recebida.data[4], sizeof(float));
////            		  memcpy(&RodaDianteiraDir, &msg_recebida.data[0], sizeof(float));
//
//
////            			// calculo velocidade media
////					  float VelMediaDianteira = (RodaDianteiraEsq + RodaDianteiraDir)/2;
//
//
////                    modelListener->updateSpeedValue((float)VelMediaDianteira);
////                    modelListener->updateDistanciaValue(valor);
////                    break;
//
////								}
//
//
////                    //(olhar com matheus)
////                case 0x000:
////                    modelListener->updateSOCValue(valor);
////                    break;
////                case 0x000:
////                	modelListener->updateTensaoCelulaMinValue(valor);
////                    break;
////
//
//
//
//                default:
//                    // Se cair aqui, o ID que chegou não é o que esperávamos
//                	ultimo_id_intruso = msg_recebida.id;
//                    id_errado_count++;
//                    break;
//            }
//        }
    }
