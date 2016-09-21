#pragma once
#include "sfwdraw.h"
class Bullet;


class Orb
{
private:
	unsigned c = sfw::loadTextureMap("./res/blackhole.png");
	unsigned int color = 0;
	float freezeTimer = 2;

public:
	float x = 0, y = 0, size = 25, Velx = 0, Vely = 10;
	bool active;
	void createOrb(float a_x, float a_y, float a_size, unsigned int a_color);
	void drawOrb();
	void updateOrb();


	//bool collides(const Orb &O);
};