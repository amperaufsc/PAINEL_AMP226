#ifndef PAGINASECRETAVIEW_HPP
#define PAGINASECRETAVIEW_HPP

#include <gui_generated/paginasecreta_screen/paginasecretaViewBase.hpp>
#include <gui/paginasecreta_screen/paginasecretaPresenter.hpp>

class paginasecretaView : public paginasecretaViewBase
{
public:
    paginasecretaView();
    virtual ~paginasecretaView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();

    virtual void giraroleta();


protected:
    int time;
    int sorteado1;
    int sorteado2;
    int sorteado3;
    float velocidaderoleta;
    int premio1posicao;


};

#endif // PAGINASECRETAVIEW_HPP
