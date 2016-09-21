#include "Splash.h"
#include "sfwdraw.h"
#include <cstdio>
void Splash::init(int a_font) { font = a_font; }

void Splash::play() { timer = 4.f; }

void Splash::draw()
{
	
	char buffer[64];
	sprintf_s(buffer, "Please Press Enter");
	sfw::drawString(font, buffer, 700, 257, 20, 20);
	//sfw::drawLine(100, 80, 100 + 500 * (timer / 4.f), 80);
}

void Splash::step() { timer -= sfw::getDeltaTime(); }

APP_STATE Splash::next()
{
	if (sfw::getKey(KEY_ENTER))
		return ENTER_OPTION;
	return SPLASH;
}