#include <iostream>
#include <cstdio>
#include "bullet.h"
#include "Player.h"
#include "game.h"
#include <random>

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
	sfw::drawCircle(x, y, 8, 12, color);
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

		
		p2.health -= 2;
		printf("%d to %d \n", p1.health, p2.health);
		active = false;

	}
	//PADDLE
	if (x + size > getCorner(p2.box, playerPos2, 0).x &&	// 3 ball must be past
		y - size < getCorner(p2.box, playerPos2, 1).y &&	// 1 bottom of ball must be less than top of the box
		y + size > getCorner(p2.box, playerPos2, 0).y)	// 2 top of the ball must be greater than the bottom of the box
	{

		
		p1.health -= 2;
		printf("%d to %d \n", p1.health, p2.health);
		active = false;
		//x = p2.x + p2.box.corners[0].x - size;
	}
	

	for (int i = 0; i < Player::MAX_AMMO_COUNT; ++i)
	{
		if (this != &p1.ammo[i])
		{
			if (collides(p1.ammo[i]))
			{
				Velx *= -1;
				Vely += randRange(-10, 10);
				p1.ammo[i].Velx *= -1;
				p1.ammo[i].Vely += randRange(-10,10);
				x += Velx * 2;
				p1.ammo[i].x += p1.ammo[i].Velx * 2;
			}
		}
	}
	for (int i = 0; i < Player::MAX_AMMO_COUNT; ++i)
	{
		if (this != &p2.ammo[i])
		{
			if (collides(p2.ammo[i]))
			{
				Velx *= -1;
				Vely += randRange(-10, 10);
				p2.ammo[i].Velx *= -1;
				p2.ammo[i].Vely += randRange(-10, 10);
				x += Velx * 2;
				p2.ammo[i].x += p2.ammo[i].Velx * 2;
			}
		}
	}

	//if (x < x)
	//{
	//	Velx *= -1;
	//}

	//if (p1.ammo[0].x > p2.ammo[0].x)
	//{
	//	Velx *= -1;
	//}


	// What is the condition for bullets to collide?
		// If their distance is small enough.





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


bool Bullet::collides(const Bullet &b)
{
	return sqrtf((x - b.x)*(x - b.x) + (y - b.y)*(y - b.y)) < size + b.size;
}