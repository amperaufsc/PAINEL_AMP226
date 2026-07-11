#ifndef TRACKDRIVE_SAPRESENTER_HPP
#define TRACKDRIVE_SAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Trackdrive_SAView;

class Trackdrive_SAPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Trackdrive_SAPresenter(Trackdrive_SAView& v);

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
    virtual ~Trackdrive_SAPresenter() {}

	//botoes
	virtual void Botao1(int bn1) override;
	virtual void Botao2(int bn2) override;
	virtual void Botao3(int bn3) override;

private:
    Trackdrive_SAPresenter();
    int missao;
    int gostatetrackdrive;
    Trackdrive_SAView& view;
};

#endif // TRACKDRIVE_SAPRESENTER_HPP
