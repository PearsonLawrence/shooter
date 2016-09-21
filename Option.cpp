#include "option.h"
#include "splash.h"
#include "Option.h"
#include "sfwdraw.h"
#include <cstdio>
void Option::init(int a_font)
{
	font = a_font;
}

void Option::play() { select = 1; timer = 2.2; }

void Option::draw()
{
	
	sfw::drawString(font, "PLAY!", 785, 575, 60, 60, 0, 0, select == 1?GREEN : BLACK);
	sfw::drawString(font, "QUIT!", 785, 515, 60, 60, 0, 0, select == 0?RED : BLACK);
	sfw::drawString(font, "Press Enter when your choice is lit up!", 650, 445, 15, 15, 0, 0, select == 3 ? GREEN : WHITE);
	sfw::drawLine(100, 80, 100 + 500 * (timer / 4.f), 80);
}

void Option::step()
{
	timer -= sfw::getDeltaTime();
	if (timer < 0)
	{
		timer = 1.f;
		select = 1 - select;
	}
}

APP_STATE Option::next()
{
	if (sfw::getKey(KEY_ENTER) && timer <= 2)
	{
		if (select == 1) return ENTER_LOAD;
		if (select == 0) return ENTER_DEPART;
		
	}
	return OPTION;
}