#ifndef TESTESPRESENTER_HPP
#define TESTESPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class TestesView;

class TestesPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    TestesPresenter(TestesView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();
    virtual void hwButtonClicked(uint8_t buttonId) override;


    virtual ~TestesPresenter() {}
    void notifyButtonChanged(uint32_t buttonID);

private:
    TestesPresenter();

    TestesView& view;
};

#endif // TESTESPRESENTER_HPP
