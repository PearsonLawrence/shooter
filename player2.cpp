#include <iostream>
#include "player.h"
#include "game.h"

void Player::createPlayer2(float a_x, float a_y, Ship rect,
	int a_up, int a_down, int a_shoot, int shootDir,
	unsigned int a_color)
{
	x = a_x;
	y = a_y;
	box = rect;
	up = a_up;
	down = a_down;
	shoot = a_shoot;
	shootDirection = shootDir;
	color = a_color;
	Vely = 8;
	shootSpeed = 0;
	health = 100;

	// create boolets
	for (int i = 0; i < MAX_AMMO_COUNT; i++)
	{
		ammo[i].createBullet(0, 0, 8, a_color);
	}
}
bool Player::isAlive()
{
	if (health < 0) { return false; }
	else
	{
		return true;
	}
}


void Player::updatePlayer2()
{
	
		// timers
		shootDelay -= sfw::getDeltaTime();

		// movement
		if (y + box.corners[0].y < randRange(randRange(randRange(0, 100), randRange(100, 199)),
			randRange(randRange(200, 500), randRange(550,900))))
		{
			Vely = randRange(5, 17);
		}
		if (y + box.corners[0].y > randRange(randRange(2, 199),
			randRange(200, 900)))
		{
			Vely = randRange(-5, -17);
		}
		
			
		

		// bounds
		if (y + box.corners[0].y < 2)
		{
			y = 2 - box.corners[0].y;

			Vely *= -1;
			 

		}

		if (y + box.corners[1].y > 950)
		{
			y = 950 - box.corners[1].y;
			Vely *= -1;;

		}
		shootSpeed = randRange(20, 30);
		fireBullet();
		y += Vely;
	
}

void Player::drawPlayer2()
{
	sfw::drawTexture(v, x - 20, y + 15, 60, 40, 0, false, 0, WHITE);
	
}
//bool Player::fireBullet()
//{
//	if (shootDelay > 0)
//	{
//		return false;
//	}
//
//	for (int i = 0; i < MAX_AMMO_COUNT; ++i)
//	{
//		if (!ammo[i].active)
//		{
//			ammo[i].active = true;
//
//			ammo[i].x = x + (35 * shootDirection);
//			ammo[i].y = y;
//
//			ammo[i].Velx = shootSpeed * shootDirection;
//			ammo[i].Vely = 0;
//
//			shootDelay = .25f;
//
//			return true;
//		}
//	}
//
//	return false;
//}