#include "depart.h"
#include "sfwdraw.h"
#include <cstdio>
void Depart::init(int a_font)
{
	font = a_font;
}

void Depart::play() { timer = 4.f; }

void Depart::draw()
{
	char buffer[64];
	sprintf_s(buffer, "EXITING GAME PLEASE WAIT", timer);
	sfw::drawString(font, buffer, 100, 120, 20, 20);
	sfw::drawLine(100, 80, 100 + 500 * (timer / 4.f), 80);
}

void Depart::step() { timer -= sfw::getDeltaTime(); }

APP_STATE Depart::next()
{
	if (timer < 0)
		return TERMINATE;
	return DEPART;
}