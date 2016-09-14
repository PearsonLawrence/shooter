#pragma once
class Player;	// forward declaration

class Bullet
{
private:	
	unsigned int color = 0;
	float freezeTimer = 2;

public:
	float x = 300, y = 400, size = 0, Velx = 10, Vely = 0;
	bool active;
	void createBullet(float x, float y, float size, unsigned int color);
	void drawBullet();
	void updateBullet(Player &p1, Player &p2);


	bool collides(const Bullet &b);
};

