#ifndef MENU_SAVIEW_HPP
#define MENU_SAVIEW_HPP

#include <gui_generated/menu_sa_screen/Menu_SAViewBase.hpp>
#include <gui/menu_sa_screen/Menu_SAPresenter.hpp>

class Menu_SAView : public Menu_SAViewBase
{
public:
    Menu_SAView();
    virtual ~Menu_SAView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MENU_SAVIEW_HPP
