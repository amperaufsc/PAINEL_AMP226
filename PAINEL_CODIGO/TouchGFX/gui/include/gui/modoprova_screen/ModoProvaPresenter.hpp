#ifndef MODOPROVAPRESENTER_HPP
#define MODOPROVAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;


class ModoProvaView;

class ModoProvaPresenter : public Presenter, public ModelListener
{
public:
    ModoProvaPresenter(ModoProvaView& v);

    virtual void activate();
    virtual void deactivate();
    virtual ~ModoProvaPresenter() {};
;

private:
    ModoProvaPresenter();
    ModoProvaView& view;
};

#endif
