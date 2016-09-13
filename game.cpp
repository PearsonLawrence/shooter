#include "game.h"
Point getCorner(Rectangle rect, Point position, int corner)
{
	Point retval;

	retval.x = rect.corners[corner].x + position.x;
	retval.y = rect.corners[corner].y + position.y;

	return retval;
}

int randRange(int start, int end)
{
	srand(time(0));
	return rand() % (end - start + 1) + start;
}


void drawRectangle(Rectangle rect, Point position)
{
	// move points
	//rect.corners[0].x += position.x;
	//rect.corners[0].y += position.y;

	rect.corners[0].x = getCorner(rect, position, 0).x;
	rect.corners[0].y = getCorner(rect, position, 0).y;

	//rect.corners[1].x += position.x;
	//rect.corners[1].y += position.y;

	rect.corners[1].x = getCorner(rect, position, 1).x;
	rect.corners[1].y = getCorner(rect, position, 1).y;

	// Left
	sfw::drawLine(rect.corners[0].x, rect.corners[0].y,
		rect.corners[0].x, rect.corners[1].y);

	// Top
	sfw::drawLine(rect.corners[0].x, rect.corners[1].y,
		rect.corners[1].x, rect.corners[1].y);

	// Right
	sfw::drawLine(rect.corners[1].x, rect.corners[1].y,
		rect.corners[1].x, rect.corners[0].y);

	// Bottom
	sfw::drawLine(rect.corners[1].x, rect.corners[0].y,
		rect.corners[0].x, rect.corners[0].y);
}

void drawWin(unsigned font)
{
	sfw::drawString(font, "Game over player 2 wins", 160, 600, 20, 20);
}

void drawWin2(unsigned font)
{
	sfw::drawString(font, "Game over player 1 wins ", 160, 600, 20, 20);
}