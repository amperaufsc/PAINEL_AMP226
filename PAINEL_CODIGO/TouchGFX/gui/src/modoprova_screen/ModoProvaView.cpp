#include <gui/modoprova_screen/ModoProvaView.hpp>
#include <touchgfx/Color.hpp>

ModoProvaView::ModoProvaView()
{

}

void ModoProvaView::setupScreen()
{
    ModoProvaViewBase::setupScreen();
}

void ModoProvaView::tearDownScreen()
{
    ModoProvaViewBase::tearDownScreen();
}

void ModoProvaView::updateTempMotor(int temp)
{
    Unicode::snprintf(Tempmotor_unBuffer, TEMPMOTOR_UN_SIZE, "%d", temp);
	Tempmotor_un.invalidate();
}

void ModoProvaView::updateTempAcc(int temp)
{
	    Unicode::snprintf(Tempacc_unBuffer, TEMPACC_UN_SIZE, "%d", temp);

	    if (temp < 15)
	    {

	    	Tempacc_un.setColor(touchgfx::Color::getColorFromRGB(92,198,208));
	    }
	    else if (temp > 55)
	    {

	    	Tempacc_un.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
	    }
	    else
	    {

	    	Tempacc_un.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
	    }


	    Tempacc_un.invalidate();
}
