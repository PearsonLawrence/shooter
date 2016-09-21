#pragma once

class Player;

class Ultimate
{
	char up = 0, down = 0, shoot = 0;

	int shootDirection = 0;
	unsigned int color = 0;
	float shootDelay;
	float timer;

public:
	float size;
	float x = 0, y = 0;
	float Vely = 10;
	
	void createUltimate(float x, float y, float size, unsigned int color);
	void updateUltimate(Player p);
	void drawUltimate();
	
	bool ultimateActive;
};