#ifndef MODOPROVAVIEW_HPP
#define MODOPROVAVIEW_HPP

#include <gui_generated/modoprova_screen/ModoProvaViewBase.hpp>
#include <gui/modoprova_screen/ModoProvaPresenter.hpp>

class ModoProvaView : public ModoProvaViewBase
{
public:
    ModoProvaView();
    virtual ~ModoProvaView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void updateButtonState(uint32_t buttonID);

protected:
};

#endif // MODOPROVAVIEW_HPP
