#pragma once
#include "sfwdraw.h"
#include <random>
#include <time.h>
#include <cstdio>
#include <iostream>


struct Ball {
	bool active;
	float x = 300, y = 400, size = 0, Velx = 0, Vely = 0;
	unsigned int color = 0;
	float freezeTimer = 2;
};

struct Paddle
{

	float x = 0, y = 0, size = 0;
	char up = 0, down = 0;
	unsigned int color = 0;

	int score = 0;

};

int randRange(int start, int end)
{
	return rand() % (end - start + 1) + start;
}



Ball createBall(float x, float y, float size, unsigned int color)
{

	Ball b;
	b.active = false;
	b.x = x;
	b.y = y;
	b.size = size;
	b.color = color;
	b.Velx = randRange(150,340);
	b.Vely = randRange(150,340);

	return b;
}

void drawBall(const Ball &b)
{
	sfw::drawCircle(b.x, b.y, b.size, 12, b.color);
}


//bool ballPaddleCollision(const Ball &b, const Paddle &p);

void updateBall(Ball &b, Paddle &p1, Paddle &p2)
{
	b.freezeTimer -= sfw::getDeltaTime();
	if (b.freezeTimer > 0) return;
	// must be less than the player's x
	// but also between the player's top and bottom
		// top    = size + y
		// bottom = y

	//PADDLE
	if (b.x - b.size < p1.x && b.y > p1.y && b.y < (p1.y+p1.size))
	{
			b.Velx *= -1;
			b.Vely += randRange(-3, 3);
			b.x = p1.x + b.size;
	}
	//PADDLE
	if (b.x + b.size > p2.x  && b.y > p2.y && b.y < (p2.y + p2.size))
	{
			b.Velx *= -1;
			b.Vely += randRange(-3, 3);
			b.x = p2.x - b.size;
	}
	
	if (b.x < 0)
		{
			p1.score++;
			b.freezeTimer = 2;
			
			printf("%d to %d \n", p1.score, p2.score);
			b.x = 30;
			b.y = 300;
			
			
			
			b.Velx *= -1;
			
		}
	if (b.x > 800)
		{
			p2.score++;
			b.freezeTimer = 2;

		printf("%d to %d \n",p1.score,p2.score);
		b.x = 770;
		b.y = 300;
		b.Velx *= -1;
		
	}

	//if (b.x < 0)
	//	b.Velx *= -1;


	//if (b.x > 800)
	//	b.Velx *= -1;

	if (b.y < 0)
		b.Vely *= -1;

	if (b.y > 600)
		b.Vely *= -1;

	b.x += b.Velx * sfw::getDeltaTime();
	b.y += b.Vely * sfw::getDeltaTime();
}



// starting position and controls
Paddle createPaddle(float x, float y, float size, char up, char down, unsigned int color)
{
	Paddle p;
	p.x = x;
	p.y = y;
	p.size = size;

	p.up = up;
	p.down = down;

	p.color = color;

	return p;
}

void updatePaddle(Paddle &p)
{
	sfw::drawLine(p.x, p.y, p.x, p.y + p.size, p.color);

	// TODO
	if (sfw::getKey(p.up))
		p.y += 17;

	if (sfw::getKey(p.down))
		p.y -= 17;


	// bounds
	if (p.y < 0) p.y = 0;
	if (p.y > 500) p.y = 500;


	//sfw::drawLine(p.x, p.y, p.x, p.y + p.size);
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





