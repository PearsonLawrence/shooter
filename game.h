#pragma once
#include "sfwdraw.h"
#include <random>
#include <time.h>
#include <cstdio>
#include <iostream>


struct Point
{
	float x, y;
};

struct Rectangle
{
	// Bottom-left and top-right corners
	Point corners[2];
};

Point getCorner(Rectangle rect, Point position, int corner);

int randRange(int start, int end);

void drawRectangle(Rectangle rect, Point position);

void drawWin(unsigned font);
void drawWin2(unsigned font);




