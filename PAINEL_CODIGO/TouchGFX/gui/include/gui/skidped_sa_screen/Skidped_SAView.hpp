#ifndef SKIDPED_SAVIEW_HPP
#define SKIDPED_SAVIEW_HPP

#include <gui_generated/skidped_sa_screen/Skidped_SAViewBase.hpp>
#include <gui/skidped_sa_screen/Skidped_SAPresenter.hpp>

class Skidped_SAView : public Skidped_SAViewBase
{
public:
    Skidped_SAView();
    virtual ~Skidped_SAView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SKIDPED_SAVIEW_HPP
