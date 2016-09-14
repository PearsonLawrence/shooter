#include "Gamestate.h"
#include "game.h"
#include "Player.h"
#include "bullet.h"
#include <time.h>

void drawhealth(unsigned font, int p1health, int p2health)
{
	char buffer[64] = { 0 };		//array 
									//_itoa_s(p1health,buffer,10);
	sprintf_s(buffer, "P2 Health:%d", p1health);
	sfw::drawString(font, buffer, 480, 600, 17, 17);

	//_itoa_s(p2health, buffer, 10);
	sprintf_s(buffer, "P1 Health:%d", p2health);
	sfw::drawString(font, buffer, 50, 600, 17, 17);
}

void GameState::init()
{
	Rectangle playerRect;

	playerRect.corners[0].x = -10;
	playerRect.corners[0].y = -50;
	playerRect.corners[1].x = 10;
	playerRect.corners[1].y = 50;

	p1.createPlayer(20, 250, playerRect, 'W', 'S', 'D', 1, GREEN);
	p2.createPlayer(780, 250, playerRect, 'I', 'K', 'J', -1, YELLOW);
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
				p1.ammo[i].updateBullet(p1, p2);

			}
			if (p2.ammo[i].active)
			{
				p2.ammo[i].updateBullet(p1, p2);
			}
		}

		// update all players
		p1.updatePlayer();
		p2.updatePlayer();


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

		p1.drawPlayer();
		p2.drawPlayer();
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