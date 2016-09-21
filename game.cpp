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
	sfw::drawString(font, "The alien has destroyed the earth", 660, 600, 20, 20);
}

void drawWin2(unsigned font)
{
	sfw::drawString(font, "You have saved the earth ", 770, 600, 20, 20);
}

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

//void drawOrb(const Orb &b)
//{
//	sfw::drawCircle(b.x, b.y, b.size, 12, b.color);
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