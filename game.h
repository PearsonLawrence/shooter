#pragma once
#include "sfwdraw.h"
#include <random>
#include <time.h>
#include <cstdio>
#include <iostream>


struct Bullet {
	bool active;
	float x = 300, y = 400, size = 0, Velx = 10, Vely = 0;
	unsigned int color = 0;
	float freezeTimer = 2;
};

struct Point
{
	float x, y;
};

struct Rectangle
{
	// Bottom-left and top-right corners
	Point corners[2];
};

Point getCorner(Rectangle rect, Point position, int corner)
{
	Point retval;

	retval.x = rect.corners[corner].x + position.x;
	retval.y = rect.corners[corner].y + position.y;

	return retval;
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



struct Player
{
	float x = 0, y = 0;
	char up = 0, down = 0, shoot = 0;

	int shootSpeed = 10;
	int shootDirection = 0;
	unsigned int color = 0;
	Rectangle box;

	const static int MAX_AMMO_COUNT = 10;
	Bullet ammo[MAX_AMMO_COUNT];

	float shootDelay;

	int score = 0;

};

bool fireBullet(Player &player)
{
	if (player.shootDelay > 0)
	{
		return false;
	}

	// 1. Find a bullet we can fire
	for (int i = 0; i < player.MAX_AMMO_COUNT; ++i)
	{
		if (!player.ammo[i].active)
		{
			player.ammo[i].active = true;

			player.ammo[i].x = player.x + (15 * player.shootDirection);
			player.ammo[i].y = player.y;
			
			player.ammo[i].Velx = player.shootSpeed * player.shootDirection;
			player.ammo[i].Vely = 0;

			player.shootDelay = .25f;

			return true;
		}
	}
	//
	return false;
}

int randRange(int start, int end)
{
	return rand() % (end - start + 1) + start;
}




Bullet createBullet(float x, float y, float size, unsigned int color)
{
	Bullet b;
	
	b.x = x;
	b.y = y;
	b.size = size;
	b.color = color;
	b.Velx = 10;
	b.Vely = 0;

	b.active = false;

	return b;
}
void drawBullet(const Bullet &b)
{
	sfw::drawCircle(b.x, b.y, b.size, 12, b.color);
}


//bool ballPaddleCollision(const Ball &b, const Paddle &p);

void updateBullet(Bullet &b, Player &p1, Player &p2)
{
	/*b.freezeTimer -= sfw::getDeltaTime();
	if (b.freezeTimer > 0) return;*/
	// must be less than the player's x
	// but also between the player's top and bottom
	// top    = size + y
	// bottom = y

	//sfw::drawLine(p1.x + p1.box.corners[1].x, p1.y + p1.box.corners[1, p1.x + p1.box.corners[1].x, p1.y + 10);	// 3
	

	//PADDLE
	Point playerPos = { p1.x, p1.y };
	Point playerPos2 = { p2.x, p2.y };

	//if(b.x - b.size < getCorner(p1.box, playerPos, 1).x)
	//	if(b.y - b.size < getCorner(p1.box, playerPos, 1).y)
	//		if (b.y + b.size > getCorner(p1.box, playerPos, 0).y)
	//		{
	//			system("pause");
	//		}

	if (b.x - b.size < getCorner(p1.box, playerPos, 1).x &&	// 3 ball must be past
		b.y - b.size < getCorner(p1.box, playerPos, 1).y &&	// 1 
		b.y + b.size > getCorner(p1.box, playerPos, 0).y)	// 2
	{
		//b.Velx *= -1;
		//b.Vely += randRange(-3, 3);
		p1.x = 20;
		p1.y = 250;
		p1.score++;
		printf("%d to %d \n", p1.score, p2.score);
		b.active = false;
		//b.x = p1.x + p1.box.corners[1].x + b.size;
	}
	//PADDLE
	if (b.x + b.size > getCorner(p2.box, playerPos2, 0).x &&	// 3 ball must be past
		b.y - b.size < getCorner(p2.box, playerPos2, 1).y &&	// 1 bottom of ball must be less than top of the box
		b.y + b.size > getCorner(p2.box, playerPos2, 0).y)	// 2 top of the ball must be greater than the bottom of the box
	{
		/*b.Velx *= -1;
		b.Vely += randRange(-3, 3);*/
		p2.x = 780;
		p2.y = 250;
		p2.score++;
		printf("%d to %d \n", p1.score, p2.score);
		b.active = false;
		//b.x = p2.x + p2.box.corners[0].x - b.size;
	}

	if (b.x < 0 || b.x > 800)
	{
		b.active = false;
	}
	/*if (b.x > 800)
	{
		p2.score++;
		b.freezeTimer = 2;

		printf("%d to %d \n", p1.score, p2.score);
		b.x = 770;
		b.y = 300;
		b.Velx *= -1;

	}*/

	//if (b.x < 0)
	//	b.Velx *= -1;


	//if (b.x > 800)
	//	b.Velx *= -1;

	if (b.y < 0)
		b.Vely *= -1;

	if (b.y > 600)
		b.Vely *= -1;

	b.x += b.Velx; //* sfw::getDeltaTime();
	b.y += b.Vely; //* sfw::getDeltaTime();
}



// starting position and controls
Player createPlayer(float x, float y, Rectangle rect,
	char up, char down, char shoot, int shootDir,
	unsigned int color)
{
	Player p;
	p.x = x;
	p.y = y;
	p.box = rect;
	p.up = up;
	p.down = down;
	p.shoot = shoot;
	p.shootDirection = shootDir;
	

	p.color = color;

	return p;
}

void updatePlayer(Player &p)
{
	p.shootDelay -= sfw::getDeltaTime();
	// TODO
	if (sfw::getKey(p.up))
	{
		p.y += 17;
	}
	if (sfw::getKey(p.down))
	{
		p.y -= 17;
	}
	if (sfw::getKey(p.shoot))
	{
		fireBullet(p);
		//createBulletp(p.x, p.y, 5, WHITE);
		//drawBullet(b[]);
	}

	// bounds
	if (p.y + p.box.corners[0].y < 0)
		p.y = 0 - p.box.corners[0].y;

	if (p.y + p.box.corners[1].y > 600)
		p.y = 600 - p.box.corners[1].y;


	//sfw::drawLine(p.x, p.y, p.x, p.y + p.size);
}

void drawPlayer(Player p)
{
	drawRectangle(p.box, {p.x, p.y});
}

void drawScore(unsigned font, int p1score, int p2score)
{
	char buffer[64] = { 0 };		//array 
									//_itoa_s(p1score,buffer,10);
	sprintf_s(buffer, "%d", p1score);
	sfw::drawString(font, buffer, 650, 600, 40, 40);

	//_itoa_s(p2score, buffer, 10);
	sprintf_s(buffer, "%d", p2score);
	sfw::drawString(font, buffer, 100, 600, 40, 40);
}

void drawWin(unsigned font)
{

	sfw::drawString(font, "Game over player 2 wins", 160, 600, 20, 20);



}

void drawWin2(unsigned font)
{

	sfw::drawString(font, "Game over player 1 wins ", 160, 600, 20, 20);



}


