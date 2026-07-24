#ifndef MODOPROVAVIEW_HPP
#define MODOPROVAVIEW_HPP

#include <gui_generated/modoprova_screen/ModoProvaViewBase.hpp>

// AQUI É A DEFINIÇÃO COMPLETA, SEM O "class ModoProvaView;" ANTES
class ModoProvaView : public ModoProvaViewBase
{
public:
	ModoProvaView();
	virtual ~ModoProvaView() {}
	virtual void setupScreen();
	virtual void tearDownScreen();

	virtual void updateTempMotor(int temp);
	virtual void updateTempInversor(int temp);
	virtual void updateTempAcc(int temp);
	virtual void updateRPM(int rpm);
	virtual void updateSOC(int soc);
	virtual void updateVelocidade(float vel);
	virtual void updateDistancia(int metros);
	virtual void updateAcelerador(int acelera);
	virtual void updateFreio(int freio);
	virtual void updatePotencia(float pot);

	virtual void handleTickEvent();
	void resetRelogio();

protected:
	uint32_t baseTick;
	int horas;
	int minutos;
	int segundos;
};

#endif
