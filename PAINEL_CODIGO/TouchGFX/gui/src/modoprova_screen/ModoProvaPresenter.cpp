#include <gui/modoprova_screen/ModoProvaView.hpp>
#include <gui/modoprova_screen/ModoProvaPresenter.hpp>
#include <gui/common/FrontendApplication.hpp> // ESSENCIAL PARA O TRANSIÇÃO DE TELA

ModoProvaPresenter::ModoProvaPresenter(ModoProvaView& v) : view(v) { }

void ModoProvaPresenter::activate() { }
void ModoProvaPresenter::deactivate() { }

void ModoProvaPresenter::hwButtonClicked(uint8_t buttonId)
{
    if (buttonId == 3)
    {
        static_cast<FrontendApplication*>(Application::getInstance())->gotoCapaScreenSlideTransitionWest();
    }
}

void ModoProvaPresenter::updateRPMValue(int val)
{
    view.updateRPMValue(val);
}
