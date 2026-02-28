#include <gui/modoprova_screen/ModoProvaView.hpp>

ModoProvaView::ModoProvaView()
{
    // Construtor vazio
}

void ModoProvaView::setupScreen()
{
    ModoProvaViewBase::setupScreen();
}

void ModoProvaView::tearDownScreen()
{
    ModoProvaViewBase::tearDownScreen();
}

void ModoProvaView::updateRPMValue(int val)
{
    tacografo.setValue(val);
    tacografo.invalidate();

    Unicode::snprintf(RPM_unBuffer, RPM_UN_SIZE, "%d", val);
    RPM_un.invalidate();
}
