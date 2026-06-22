#ifndef CAPAVIEW_HPP
#define CAPAVIEW_HPP

#include <gui_generated/capa_screen/CapaViewBase.hpp>
#include <gui/capa_screen/CapaPresenter.hpp>
#include <touchgfx/widgets/Image.hpp>

class CapaView : public CapaViewBase
{
public:
    CapaView();
    virtual ~CapaView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    // Sobrescreve o handleTickEvent nativo
    virtual void handleTickEvent();

protected:
    int tickCounter;

};

#endif // CAPAVIEW_HPP
