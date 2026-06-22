#ifndef TRACKDRIVE_SAVIEW_HPP
#define TRACKDRIVE_SAVIEW_HPP

#include <gui_generated/trackdrive_sa_screen/Trackdrive_SAViewBase.hpp>
#include <gui/trackdrive_sa_screen/Trackdrive_SAPresenter.hpp>

class Trackdrive_SAView : public Trackdrive_SAViewBase
{
public:
    Trackdrive_SAView();
    virtual ~Trackdrive_SAView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // TRACKDRIVE_SAVIEW_HPP
