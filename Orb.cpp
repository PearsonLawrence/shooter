#include <iostream>
#include "Orb.h"
#include "game.h"
#include "bullet.h"
#include "player.h"
void Orb::createOrb(float a_x, float a_y, float a_size, unsigned int a_color)
{
	x = a_x;
	y = a_y;
	size = a_size;
	color = a_color;
	Velx = 5;
	Vely = 5;

	active = true;

}

void Orb::drawOrb()
{
	sfw::drawTexture(c, x - 50, y + 50, 200, 200, 0, false, 0, color);
	
}

void Orb::updateOrb()
{
	if (y < 0)
	{
		Vely *= -1;
		//size = randRange(5, 40);
		//color = RED;
	}
	if (y > 950)
	{
		Vely *= -1;
		//size = randRange(5, 40);
		//color = BLUE;
	}

	if (x < 875)
	{
		Velx *= -1;
		//size = randRange(randRange(10, 20), randRange(21, 60));
		//color = WHITE;
	}
	if (x > 1075)
	{
		Velx *= -1;
		//size = randRange(randRange(5,6), randRange(10, 30));
		//color = WHITE;
	}

	//x += Velx; //* sfw::getDeltaTime();
	y += Vely;
	x += Velx;
}