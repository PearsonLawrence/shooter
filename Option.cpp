#include "option.h"
#include "splash.h"
#include "Option.h"
#include "sfwdraw.h"
#include <cstdio>
void Option::init(int a_font)
{
	font = a_font;
}

void Option::play() { select = 1; timer = 2.f; }

void Option::draw()
{
	
	sfw::drawString(font, "PLAY!", 270, 440, 20, 20, 0, 0, select == 1?GREEN : BLACK);
	sfw::drawString(font, "QUIT!", 270, 410, 20, 20, 0, 0, select == 0?RED : BLACK);
	sfw::drawString(font, "Press TAB when your choice is lit up!", 200, 380, 15, 15, 0, 0, select == 3 ? GREEN : WHITE);
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
	if (sfw::getKey(KEY_TAB))
	{
		if (select == 1) return ENTER_ACTION;
		if (select == 0) return ENTER_DEPART;
		
	}
	return OPTION;
}