#include "Gamestate.h"
#include "game.h"
#include "Player.h"
#include "bullet.h"
#include <time.h>
#include "orb.h"

void drawhealth(unsigned font, int p1health, int p2health)
{
	char buffer[64] = { 0 };		//array 
									//_itoa_s(p1health,buffer,10);
	sprintf_s(buffer, "P2 Health:%d", p1health);
	sfw::drawString(font, buffer, 1555, 920, 17, 17, 0, 0, YELLOW);

	//_itoa_s(p2health, buffer, 10);
	sprintf_s(buffer, "P1 Health:%d", p2health);
	sfw::drawString(font, buffer, 100, 920, 17, 17, 0, 0, GREEN);
}

void GameState::init()
{
	//Orb orb;
	sfw::loadTextureMap("./res/background.jpg");
	Rectangle playerRect;
	//Orb b;

	playerRect.corners[0].x = -10;
	playerRect.corners[0].y = -30;
	playerRect.corners[1].x = 10;
	playerRect.corners[1].y = 30;
	//createOrb(300, 400, 15, RED);
	p1.createPlayer(30, 475, playerRect, 'W', 'S', 'D', 1, GREEN);
	p2.createPlayer(1860, 475, playerRect, 'I', 'K', 'J', -1, YELLOW);
	o.createOrb(945, 475, 30, WHITE);
	gameOver = false;
}

void GameState::update()
{
	// Input/Logic Step
	if (!gameOver)
	{

		// update all bullets
		for (int i = 0; i < Player::MAX_AMMO_COUNT; ++i)
		{
			if (p1.ammo[i].active)
			{
				p1.ammo[i].updateBullet(p1, p2, o);

			}
			if (p2.ammo[i].active)
			{
				p2.ammo[i].updateBullet(p1, p2, o);
			}
		}

		// update all players
		p1.updatePlayer();
		p2.updatePlayer();
		o.updateOrb();

		// Two arrays
		// Each

	}
}

void GameState::drawRound()
{
	if (!gameOver)
	{
		for (int i = 0; i < Player::MAX_AMMO_COUNT; ++i)
		{
			if (p1.ammo[i].active)
			{
				p1.ammo[i].drawBullet();
			}
			if (p2.ammo[i].active)
			{
				p2.ammo[i].drawBullet();
			}
		}
		
		//drawOrb(b);
		p1.drawPlayer();
		p2.drawPlayer();
		o.drawOrb();
		drawhealth(d, p1.health, p2.health);
	}
	if (p1.health <= 0)
	{
		gameOver = true;
		drawWin2(d);
	}
	if (p2.health <= 0)
	{
		gameOver = true;
		drawWin(d);
	}

	/*if (!gameOver)
	{
		for (int i = 0; i < Player::MAX_AMMO_COUNT; ++i)
		{
			if (p1.ammo[i].active)
			{
				p1.ammo[i].drawBullet();
			}
			if (p2.ammo[i].active)
			{
				p2.ammo[i].drawBullet();
			}
		}

		p1.drawPlayer();
		p2.drawPlayer();
		drawhealth(d, p1.health, p2.health);
	}
	if (p1.health <= 0)
	{
		gameOver = true;
		drawWin(d);
	}
	if (p2.health <= 15)
	{
		gameOver = true;
		drawWin2(d);
	}*/
}
void GameState::play() { timer = 2.f; }
APP_STATE GameState::next()
{
	if (gameOver)
	{
		
			return ENTER_NEXT;
		
     }
	else
		return ACTION;
}