#include <gui/capa_screen/CapaView.hpp>

CapaView::CapaView() :
tickCounter(0)
{
}

void CapaView::setupScreen()
{
	CapaViewBase::setupScreen();

	// Estado inicial: logo visível, TODOS os carrinhos escondidos
	logobranca.setVisible(true);
	image1.setVisible(false);
	image2.setVisible(false);
	image3.setVisible(false);
	image4.setVisible(false);
	image5.setVisible(false);
	image6.setVisible(false);
	image7.setVisible(false);
	image8.setVisible(false);
	image9.setVisible(false);
	image10.setVisible(false);
	image11.setVisible(false);
	image12.setVisible(false);
	image13.setVisible(false);
	image14.setVisible(false);
	image15.setVisible(false);
	image16.setVisible(false);

	logobranca.invalidate();
}

void CapaView::tearDownScreen()
{
	CapaViewBase::tearDownScreen();
}

void CapaView::handleTickEvent()
{
	CapaViewBase::handleTickEvent();

	tickCounter++;

	// Ciclo total de 4 segundos (240 ticks a 60Hz)
	if (tickCounter >= 240)
	{
		tickCounter = 0;
	}

	// ====================================================================
	// PRIMEIROS 2 SEGUNDOS (0 a 119): Logo ligada, animação parada
	// ====================================================================
	if (tickCounter < 120)
	{
		if (!logobranca.isVisible())
		{
			logobranca.setVisible(true);


			logobranca.invalidate();

			// Apaga o último frame do ciclo anterior
			image16.setVisible(false);
			image16.invalidate();
		}
	}
	// ====================================================================
	// PRÓXIMOS 2 SEGUNDOS (120 a 239): Logo some, sequência roda
	// ====================================================================
	else
	{
		if (logobranca.isVisible())
		{
			logobranca.setVisible(false);
			logobranca.invalidate();
		}

		// Dividindo 16 frames nos 120 ticks (aproximadamente 7 a 8 ticks por frame)
		if (tickCounter >= 120 && tickCounter < 127)
		{
			if (!image1.isVisible()) { image1.setVisible(true); image1.invalidate(); }
		}
		else if (tickCounter >= 127 && tickCounter < 135)
		{
			if (image1.isVisible()) { image1.setVisible(false); image1.invalidate(); }
			if (!image2.isVisible()) { image2.setVisible(true); image2.invalidate(); }
		}
		else if (tickCounter >= 135 && tickCounter < 142)
		{
			if (image2.isVisible()) { image2.setVisible(false); image2.invalidate(); }
			if (!image3.isVisible()) { image3.setVisible(true); image3.invalidate(); }
		}
		else if (tickCounter >= 142 && tickCounter < 150)
		{
			if (image3.isVisible()) { image3.setVisible(false); image3.invalidate(); }
			if (!image4.isVisible()) { image4.setVisible(true); image4.invalidate(); }
		}
		else if (tickCounter >= 150 && tickCounter < 157)
		{
			if (image4.isVisible()) { image4.setVisible(false); image4.invalidate(); }
			if (!image5.isVisible()) { image5.setVisible(true); image5.invalidate(); }
		}
		else if (tickCounter >= 157 && tickCounter < 165)
		{
			if (image5.isVisible()) { image5.setVisible(false); image5.invalidate(); }
			if (!image6.isVisible()) { image6.setVisible(true); image6.invalidate(); }
		}
		else if (tickCounter >= 165 && tickCounter < 172)
		{
			if (image6.isVisible()) { image6.setVisible(false); image6.invalidate(); }
			if (!image7.isVisible()) { image7.setVisible(true); image7.invalidate(); }
		}
		else if (tickCounter >= 172 && tickCounter < 180)
		{
			if (image7.isVisible()) { image7.setVisible(false); image7.invalidate(); }
			if (!image8.isVisible()) { image8.setVisible(true); image8.invalidate(); }
		}
		else if (tickCounter >= 180 && tickCounter < 187)
		{
			if (image8.isVisible()) { image8.setVisible(false); image8.invalidate(); }
			if (!image9.isVisible()) { image9.setVisible(true); image9.invalidate(); }
		}
		else if (tickCounter >= 187 && tickCounter < 195)
		{
			if (image9.isVisible()) { image9.setVisible(false); image9.invalidate(); }
			if (!image10.isVisible()) { image10.setVisible(true); image10.invalidate(); }
		}
		else if (tickCounter >= 195 && tickCounter < 202)
		{
			if (image10.isVisible()) { image10.setVisible(false); image10.invalidate(); }
			if (!image11.isVisible()) { image11.setVisible(true); image11.invalidate(); }
		}
		else if (tickCounter >= 202 && tickCounter < 210)
		{
			if (image11.isVisible()) { image11.setVisible(false); image11.invalidate(); }
			if (!image12.isVisible()) { image12.setVisible(true); image12.invalidate(); }
		}
		else if (tickCounter >= 210 && tickCounter < 217)
		{
			if (image12.isVisible()) { image12.setVisible(false); image12.invalidate(); }
			if (!image13.isVisible()) { image13.setVisible(true); image13.invalidate(); }
		}
		else if (tickCounter >= 217 && tickCounter < 225)
		{
			if (image13.isVisible()) { image13.setVisible(false); image13.invalidate(); }
			if (!image14.isVisible()) { image14.setVisible(true); image14.invalidate(); }
		}
		else if (tickCounter >= 225 && tickCounter < 232)
		{
			if (image14.isVisible()) { image14.setVisible(false); image14.invalidate(); }
			if (!image15.isVisible()) { image15.setVisible(true); image15.invalidate(); }
		}
		else if (tickCounter >= 232 && tickCounter < 240)
		{
			if (image15.isVisible()) { image15.setVisible(false); image15.invalidate(); }
			if (!image16.isVisible()) { image16.setVisible(true); image16.invalidate(); }
		}
	}
}
