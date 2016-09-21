#pragma once

#include "bullet.h"
#include "game.h"

class Player
{
	unsigned u = sfw::loadTextureMap("./res/spaceship.png");
	unsigned v = sfw::loadTextureMap("./res/enemy.png");
	char up = 0, down = 0, shoot = 0;

	
	int shootDirection = 0;
	unsigned int color = 0;
	float shootDelay;
	
public:
	Rectangle box;
	int health = 0;
	float x = 0, y = 0;
	float Vely = 10;
	int shootSpeed = 0;
	int scoreStreak = 0;
	const static int MAX_AMMO_COUNT = 15;
	Bullet ammo[MAX_AMMO_COUNT];

	void createPlayer(float x, float y, Rectangle rect,
		char up, char down, char shoot, int shootDir,
		unsigned int color);
	void updatePlayer();
	void drawPlayer();
	void createPlayer2(float x, float y, Rectangle rect,
		int up, int down, int shoot, int shootDir,
		unsigned int color);
	void updatePlayer2();
	void drawPlayer2();
	bool isAlive();
	bool fireBullet();
};