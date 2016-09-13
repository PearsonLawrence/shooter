#pragma once

#include "bullet.h"
#include "game.h"

class Player
{
	char up = 0, down = 0, shoot = 0;

	int shootSpeed = 10;
	int shootDirection = 0;
	unsigned int color = 0;
	float shootDelay;
	
public:
	Rectangle box;
	int score = 0;
	float x = 0, y = 0;

	const static int MAX_AMMO_COUNT = 10;
	Bullet ammo[MAX_AMMO_COUNT];

	void createPlayer(float x, float y, Rectangle rect,
		char up, char down, char shoot, int shootDir,
		unsigned int color);
	void updatePlayer();
	void drawPlayer();

	bool fireBullet();
};