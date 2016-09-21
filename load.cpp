#include "load.h"

#include "next.h"
#include "sfwdraw.h"
#include <cstdio>
void Load::init(int a_font) { font = a_font; }

void Load::play() { timer = 4.f; }

void Load::draw()
{
	char buffer[64];
	sprintf_s(buffer, "Please Press ENTER to start the game.");
	sfw::drawString(font, buffer, 700, 200, 15, 15);
	//sfw::drawLine(100, 80, 100 + 500 * (timer / 4.f), 80);
}

void Load::step() { timer -= sfw::getDeltaTime(); }

APP_STATE Load::load()
{
	if (sfw::getKey(KEY_ENTER) && timer <= 2)
	{
		return ENTER_ACTION;
	}
		
	return LOAD;
}