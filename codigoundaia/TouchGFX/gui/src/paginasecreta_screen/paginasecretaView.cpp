#include <gui/paginasecreta_screen/paginasecretaView.hpp>
#include <cmath>
#include <stdlib.h>

paginasecretaView::paginasecretaView()
{

}

void paginasecretaView::setupScreen()
{
    paginasecretaViewBase::setupScreen();
}

void paginasecretaView::tearDownScreen()
{
    paginasecretaViewBase::tearDownScreen();
}
void paginasecretaView::giraroleta()
{
	sorteado1 = rand() % 5 ;
	switch(sorteado1)
		{
	case 0:{ premio1posicao = 85; }
	break;
	case 1:{ premio1posicao = 170; }
	break;
	case 2:{ premio1posicao = 255; }
	break;
	case 3:{ premio1posicao = 340; }
	break;
	case 4:{ premio1posicao = 424; }
	break;
		}

	velocidaderoleta = 15.0f;

}
void paginasecretaView::handleTickEvent()
{
	float giroY = rolo1.getY();
	if(velocidaderoleta > 0){
	giroY += velocidaderoleta;

	if (giroY >= 424.0f){giroY = 0;}
	velocidaderoleta *= 0.99f;

	if(velocidaderoleta < 4){
		if (abs(giroY - premio1posicao) <= velocidaderoleta)
		{
			giroY = premio1posicao; // Crava no pixel exato
			velocidaderoleta = 0;

		}
	}
	}
	rolo1.setY((int)giroY);
	rolo1.invalidate();
}
