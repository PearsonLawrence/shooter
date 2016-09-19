#include <iostream>
#include "player.h"
#include "game.h"

void Player::createPlayer(float a_x, float a_y, Rectangle rect,
	char a_up, char a_down, char a_shoot, int shootDir,
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


	health = 100;

	// create boolets
	for (int i = 0; i < MAX_AMMO_COUNT; i++)
	{
		ammo[i].createBullet(0, 0, 8, a_color);
	}
}

void Player::updatePlayer()
{
	// timers
	shootDelay -= sfw::getDeltaTime();

	// movement
	if (sfw::getKey(up))
	{
		y += 17;
	}
	if (sfw::getKey(down))
	{
		y -= 17;
	}
	if (sfw::getKey(shoot))
	{
		fireBullet();
	}

	// bounds
	if (y + box.corners[0].y < 2)
		y = 2 - box.corners[0].y;

	if (y + box.corners[1].y > 950)
		y = 950 - box.corners[1].y;
}

void Player::drawPlayer()
{
	drawRectangle(box, { x, y });
}
bool Player::fireBullet()
{
	if (shootDelay > 0)
	{
		return false;
	}

	for (int i = 0; i < MAX_AMMO_COUNT; ++i)
	{
		if (!ammo[i].active)
		{
			ammo[i].active = true;

			ammo[i].x = x + (35 * shootDirection);
			ammo[i].y = y;

			ammo[i].Velx = shootSpeed * shootDirection;
			ammo[i].Vely = 0;

			shootDelay = .25f;

			return true;
		}
	}

	return false;
}