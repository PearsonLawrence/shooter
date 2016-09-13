#include <iostream>
#include <cstdio>
#include "bullet.h"
#include "Player.h"
#include "game.h"

void Bullet::createBullet(float a_x, float a_y, float a_size, unsigned int a_color)
{

	x = a_x;
	y = a_y;
	size = a_size;
	color = a_color;
	Velx = 10;
	Vely = 0;

	active = false;
}

void Bullet::drawBullet()
{
	sfw::drawCircle(x, y, size, 12, color);
}

void Bullet::updateBullet(Player &p1, Player &p2)
{
	//PADDLE
	Point playerPos = { p1.x, p1.y };
	Point playerPos2 = { p2.x, p2.y };

	if (x - size < getCorner(p1.box, playerPos, 1).x &&	// 3 ball must be past
		y - size < getCorner(p1.box, playerPos, 1).y &&	// 1 
		y + size > getCorner(p1.box, playerPos, 0).y)	// 2
	{

		p1.x = 20;
		p1.y = 250;
		p1.score++;
		printf("%d to %d \n", p1.score, p2.score);
		active = false;

	}
	//PADDLE
	if (x + size > getCorner(p2.box, playerPos2, 0).x &&	// 3 ball must be past
		y - size < getCorner(p2.box, playerPos2, 1).y &&	// 1 bottom of ball must be less than top of the box
		y + size > getCorner(p2.box, playerPos2, 0).y)	// 2 top of the ball must be greater than the bottom of the box
	{

		p2.x = 780;
		p2.y = 250;
		p2.score++;
		printf("%d to %d \n", p1.score, p2.score);
		active = false;
		//x = p2.x + p2.box.corners[0].x - size;
	}

	if (x < 0 || x > 800)
	{
		active = false;
	}


	if (y < 0)
		Vely *= -1;

	if (y > 600)
		Vely *= -1;

	x += Velx; //* sfw::getDeltaTime();
	y += Vely; //* sfw::getDeltaTime();
}