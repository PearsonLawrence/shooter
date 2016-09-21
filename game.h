#pragma once
#include "sfwdraw.h"
#include <random>
#include <time.h>
#include <cstdio>
#include <iostream>
//
//struct Orb {
//	bool active;
//	float x = 300, y = 400, size = 0, Velx = 0, Vely = 0;
//	unsigned int color = 0;
//	float freezeTimer = 2;
//};
struct Point
{
	float x, y;
};

struct Ship
{
	// Bottom-left and top-right corners
	Point corners[2];
};

Point getCorner(Ship rect, Point position, int corner);

int randRange(int start, int end);

void drawShip(Ship rect, Point position);

void drawWin(unsigned font);
void drawWin2(unsigned font);

//Orb createOrb(float x, float y, float size, unsigned int color)
//{
//
//	Orb b;
//	b.active = false;
//	b.x = x;
//	b.y = y;
//	b.size = size;
//	b.color = color;
//	b.Velx = 0;
//	b.Vely = randRange(150, 340);
//
//	return b;
//}
//
//void drawOrb(const Orb &b)
//{
//	sfw::drawCircle(b.x, b.y, b.size, 12, b.color);
//
//}
//void updateOrb(Orb &b)
//{
//
//	if (b.y < 0)
//		b.Vely *= -1;
//
//	if (b.y > 600)
//		b.Vely *= -1;
//}
//

