#include <gui/modoprova_screen/ModoProvaView.hpp>
#include <gui/modoprova_screen/ModoProvaPresenter.hpp>

ModoProvaPresenter::ModoProvaPresenter(ModoProvaView& v)
    : view(v)
{

}

void ModoProvaPresenter::activate()
{

}

void ModoProvaPresenter::deactivate()
{

}
void ModoProvaPresenter::hwButtonClicked(uint8_t buttonId)
{

	    if (buttonId == 2) // PB11 BOLINHA
	    {
	        static_cast<FrontendApplication*>(Application::getInstance())->gotoCapaScreenSlideTransitionWest();
	    }

}
