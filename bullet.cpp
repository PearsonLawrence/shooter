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
	sfw::drawTexture(n, x -15, y + 15, 30, 30, 0, false, 0, color);
//	sfw::drawCircle(x, y, size, 12, color);

}

void Bullet::updateBullet(Player &p1, Player &p2, Orb &o)
{
	//PADDLE
	Point playerPos = { p1.x, p1.y };
	Point playerPos2 = { p2.x, p2.y };

	/*if (p2.scoreStreak >= 5 && sfw::getKey('E'))
	{
		active = false;
		p2.scoreStreak = 0;
	}*/

	if (x - size < getCorner(p1.box, playerPos, 1).x &&	// 3 ball must be past
		y - size < getCorner(p1.box, playerPos, 1).y &&	// 1 
		y + size > getCorner(p1.box, playerPos, 0).y)	// 2
	{

		if (color == GREEN)
		{
			p2.health -= 1;
			printf("%d to %d \n", p1.health, p2.health);
			active = false;
		}

		else if (color == YELLOW)
		{
			//p1.scoreStreak++;
			p2.health -= 2;
			printf("%d to %d \n", p1.health, p2.health);
			active = false;
		}


	}
	if (p2.scoreStreak >= 10 && sfw::getKey('E'))
	{
		p2.health += 10;
		p2.scoreStreak = 0;
	}
	//PADDLE
	if (x + size > getCorner(p2.box, playerPos2, 0).x &&	// 3 ball must be past
		y - size < getCorner(p2.box, playerPos2, 1).y &&	// 1 bottom of ball must be less than top of the box
		y + size > getCorner(p2.box, playerPos2, 0).y)	// 2 top of the ball must be greater than the bottom of the box
	{

		
		if (color == GREEN)
		{
			p2.scoreStreak++;
			p1.health -= 2;
			printf("%d to %d \n", p1.health, p2.health);
			active = false;
		}

		else if (color == YELLOW)
		{

			p1.health += 1.f;
			printf("%d to %d \n", p1.health, p2.health);
			active = false;
		}

		//x = p2.x + p2.box.corners[0].x - size;
	}
	

	/*for (int i = 0; i < Player::MAX_AMMO_COUNT; ++i)
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
	}*/
	


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
		
			if (p1.ammo[i].x + size> o.x - o.size && p1.ammo[i].y < o.y + o.size 
				&& p1.ammo[i].y > o.y - o.size)
			{
				//Velx += 1;
				p1.ammo[i].Vely = randRange(-10, 10);
			
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
			if (p2.ammo[i].x + size < o.x + o.size && p2.ammo[i].y < o.y + o.size 
				&& p2.ammo[i].y > o.y - o.size)
			{
				//Velx *= randRange(5, 10);
				p2.ammo[i].Vely = randRange(-10, 10);
				
			}
			
			//if (p2.ammo[i].x < o.x && p2.ammo[i].y < o.y + o.size && p2.ammo[i].y > o.y - o.size)
			//{
			//	//Velx *= randRange(5, 10);
			//	Vely *= randRange(-5, 5);
			//	color = WHITE;
			//}
			//if (p2.ammo[i].x > o.x && p2.ammo[i].y < o.y + o.size && p2.ammo[i].y > o.y - o.size)
			//{
			//	//Velx += 1;
			//	Vely += randRange(-5, 5);
			//	color = WHITE;
			//}

		}
	}



	if (x < 10 || x > 1880)
	{
		active = false;
	}


	if (y < 0)
		Vely *= -1;

	if (y > 950)
		Vely *= -1;


	//if (x < o.x && y < o.y + o.size && y > o.y - o.size )
	//{
	//	//Velx *= randRange(5, 10);
	//	Vely *= randRange(-5, 5);
	//	color = WHITE;
	//}
	//if (x > o.x && y < o.y + o.size && y > o.y - o.size)
	//{
	//	//Velx += 1;
	//	Vely += randRange(-5, 5);
	//	color = WHITE;
	//}

	
	x += Velx; //* sfw::getDeltaTime();
	y += Vely; //* sfw::getDeltaTime();
}


bool Bullet::collides(const Bullet &b)
{
	return sqrtf((x - b.x)*(x - b.x) + (y - b.y)*(y - b.y)) < size + b.size;
}