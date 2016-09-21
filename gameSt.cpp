#include "Gamestate.h"
#include "game.h"
#include "Player.h"
#include "bullet.h"
#include <time.h>
#include "orb.h"

void drawhealth(unsigned font, int p1health, int p2health, int ultimate)
{
	char buffer[64] = { 0 };		//array 
									//_itoa_s(p1health,buffer,10);
	sprintf_s(buffer, "Alien Health:%d", p1health);
	sfw::drawString(font, buffer, 1555, 920, 17, 17, 0, 0, YELLOW);

	//_itoa_s(p2health, buffer, 10);
	sprintf_s(buffer, "P1 Health:%d", p2health);
	sfw::drawString(font, buffer, 100, 920, 17, 17, 0, 0, GREEN);

	
	if (ultimate >= 10)
	{
		sfw::drawString(font, "Ultimate Charge: 100% ", 100, 900, 17, 17, 0, 0, GREEN);
		sfw::drawString(font, "PRESS E FOR HEALTH BOOST", 100, 870, 17, 17, 0, 0, YELLOW);

	}
	else if (ultimate >= 9)
	{
		sfw::drawString(font, "Ultimate Charge: 90%", 100, 900, 17, 17, 0, 0, GREEN);

	}
	else if (ultimate >= 8)
	{
		sfw::drawString(font, "Ultimate Charge: 80%", 100, 900, 17, 17, 0, 0, GREEN);
	}
	else if (ultimate >= 7)
	{
		sfw::drawString(font, "Ultimate Charge: 70%", 100, 900, 17, 17, 0, 0, GREEN);
	}
	else if (ultimate >= 6)
	{
		sfw::drawString(font, "Ultimate Charge: 60%", 100, 900, 17, 17, 0, 0, GREEN);
	}
	else if (ultimate >= 5)
	{
		sfw::drawString(font, "Ultimate Charge: 50%", 100, 900, 17, 17, 0, 0, GREEN);
		
	}
	else if (ultimate >= 4)
	{
		sfw::drawString(font, "Ultimate Charge: 40%", 100, 900, 17, 17, 0, 0, GREEN);
		
	}
	else if (ultimate >= 3)
	{
		sfw::drawString(font, "Ultimate Charge: 30%", 100, 900, 17, 17, 0, 0, GREEN);
		
	}
	else if (ultimate >= 2)
	{
		sfw::drawString(font, "Ultimate Charge: 20%", 100, 900, 17, 17, 0, 0, GREEN);
	}
	else if (ultimate >= 1)
	{
		sfw::drawString(font, "Ultimate Charge: 10%", 100, 900, 17, 17, 0, 0, GREEN);
	}
	else if (ultimate >= 0)
	{
		sfw::drawString(font, "Ultimate Charge: 0%", 100, 900, 17, 17, 0, 0, GREEN);
	}

}

void GameState::init()
{
	//Orb orb;
	sfw::loadTextureMap("./res/background.jpg");
	Rectangle playerRect;
	//Orb b;

	playerRect.corners[0].x = -20;
	playerRect.corners[0].y = -20;
	playerRect.corners[1].x = 50;
	playerRect.corners[1].y = 20;
	//createOrb(300, 400, 15, RED);
	p1.createPlayer(30, 475, playerRect, 'W', 'S', 'D', 1, GREEN);
	p2.createPlayer2(1840, 475, playerRect, 1, 1, 1, -1, YELLOW);
	o.createOrb(945, 475, 50, WHITE);
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
		p2.updatePlayer2();
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
		p2.drawPlayer2();
		o.drawOrb();
		drawhealth(d, p1.health, p2.health, p2.scoreStreak);
	}
	if (p1.health <= 0)
	{
		sfw::drawTexture(y, 0, 980, 1890, 995, 0, false, 0);
		gameOver = true;
		drawWin2(d);
	}
	if (p2.health <= 0)
	{
		sfw::drawTexture(t, 0, 980, 1890, 995, 0, false, 0);
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