#include "Gamestate.h"
#include "game.h"
#include "Player.h"
#include "bullet.h"

void drawScore(unsigned font, int p1score, int p2score)
{
	char buffer[64] = { 0 };		//array 
									//_itoa_s(p1score,buffer,10);
	sprintf_s(buffer, "%d", p1score);
	sfw::drawString(font, buffer, 650, 600, 40, 40);

	//_itoa_s(p2score, buffer, 10);
	sprintf_s(buffer, "%d", p2score);
	sfw::drawString(font, buffer, 100, 600, 40, 40);
}

void GameState::init()
{
	Rectangle playerRect;

	playerRect.corners[0].x = -10;
	playerRect.corners[0].y = -50;
	playerRect.corners[1].x = 10;
	playerRect.corners[1].y = 50;

	p1.createPlayer(20, 250, playerRect, 'W', 'S', 'D', 1, BLUE);
	p2.createPlayer(780, 250, playerRect, 'I', 'K', 'J', -1, RED);
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
		drawScore(d, p1.score, p2.score);
	}
	if (p1.score >= 15)
	{
		gameOver = true;
		drawWin(d);
	}
	if (p2.score >= 15)
	{
		gameOver = true;
		drawWin2(d);
	}

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
		drawScore(d, p1.score, p2.score);
	}
	if (p1.score >= 15)
	{
		gameOver = true;
		drawWin(d);
	}
	if (p2.score >= 15)
	{
		gameOver = true;
		drawWin2(d);
	}
}