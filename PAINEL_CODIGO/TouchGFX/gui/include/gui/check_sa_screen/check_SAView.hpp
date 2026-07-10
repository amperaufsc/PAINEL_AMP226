#ifndef CHECK_SAVIEW_HPP
#define CHECK_SAVIEW_HPP

#include <gui_generated/check_sa_screen/check_SAViewBase.hpp>
#include <gui/check_sa_screen/check_SAPresenter.hpp>

class check_SAView : public check_SAViewBase
{
public:
    check_SAView();
    virtual ~check_SAView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CHECK_SAVIEW_HPP
