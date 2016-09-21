#include "next.h"
#include "sfwdraw.h"
#include <cstdio>
void Next::init(int a_font) { font = a_font; }

void Next::play() { timer = 4.f; }

void Next::draw()
{
	
	
	char buffer[64];
	sprintf_s(buffer, "Please Press ESC to return to menu.");
	sfw::drawString(font, buffer, 700, 290, 15, 15);
	//sfw::drawLine(100, 80, 100 + 500 * (timer / 4.f), 80);
}

void Next::step() { timer -= sfw::getDeltaTime(); }

APP_STATE Next::next()
{
	if (sfw::getKey(KEY_ESCAPE))
		return ENTER_OPTION;
	return NEXT;
}