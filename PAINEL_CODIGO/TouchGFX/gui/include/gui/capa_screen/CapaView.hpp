#ifndef CAPAVIEW_HPP
#define CAPAVIEW_HPP

#include <gui_generated/capa_screen/CapaViewBase.hpp>
#include <gui/capa_screen/CapaPresenter.hpp>

class CapaView : public CapaViewBase
{
public:
    CapaView();
    virtual ~CapaView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void updateButtonState(uint32_t buttonID);
    void setCANValue(int value);
    virtual void modoespera();
protected:
    int piscarimagem;
};

#endif // CAPAVIEW_HPP
