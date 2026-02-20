#include <gui/testes_screen/TestesView.hpp>
#include <gui/testes_screen/TestesPresenter.hpp>

TestesPresenter::TestesPresenter(TestesView& v)
    : view(v)
{

}

void TestesPresenter::activate()
{

}

void TestesPresenter::deactivate()
{

}

void TestesPresenter::hwButtonClicked(uint8_t buttonId)
{

	    if (buttonId == 2) // PB11
	    {
	        static_cast<FrontendApplication*>(Application::getInstance())->gotoCapaScreenSlideTransitionWest();
	    }

}
