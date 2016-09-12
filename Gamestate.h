#include "game.h"
#include "sfwdraw.h"
#include <iostream>
#include <cstdio>

//void main()
struct GameState
{
	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned r = sfw::loadTextureMap("./res/background.jpg");
	unsigned u = sfw::loadTextureMap("./res/crosshair.png");

	float acc = 10;
	float acc2 = 10;

	Player p1, p2;
	Rectangle playerRect;
	bool gameOver = false;

	//Rectangle playerRect;
	//playerRect.corners[0].x = -10;
	//playerRect.corners[0].y = -50;
	//playerRect.corners[1].x = 10;
	//playerRect.corners[1].y = 50;

	//Player p1 = createPlayer(20, 250, playerRect, 'W', 'S', 'D', 1, BLUE),
	//	p2 = createPlayer(780, 250, playerRect, 'I', 'K', 'J', -1, RED);

	//// Create all of the bullets
	//for (int i = 0; i < Player::MAX_AMMO_COUNT; i++)
	//{
	//	p1.ammo[i] = createBullet(0, 0, 5, WHITE);
	//}
	//for (int i = 0; i < Player::MAX_AMMO_COUNT; i++)
	//{
	//	p2.ammo[i] = createBullet(0, 0, 5, WHITE);
	//}


};

void createGamestate(GameState &gs)
{
	Rectangle playerRect;
	
	gs.playerRect.corners[0].x = -10;
	gs.playerRect.corners[0].y = -50;
	gs.playerRect.corners[1].x = 10;
	gs.playerRect.corners[1].y = 50;

	gs.p1 = createPlayer(20, 250, gs.playerRect, 'W', 'S', 'D', 1, BLUE);
	gs.p2 = createPlayer(780, 250, gs.playerRect, 'I', 'K', 'J', -1, RED);

	// Create all of the bullets
	for (int i = 0; i < Player::MAX_AMMO_COUNT; i++)
	{
		gs.p1.ammo[i] = createBullet(0, 0, 5, WHITE);
	}
	for (int i = 0; i < Player::MAX_AMMO_COUNT; i++)
	{
		gs.p2.ammo[i] = createBullet(0, 0, 5, WHITE);
	}
}
void updateGamestate(GameState &gs)

{
	// Input/Logic Step
	if (!gs.gameOver)
	{
		for (int i = 0; i < Player::MAX_AMMO_COUNT; ++i)
		{
			if (gs.p1.ammo[i].active)
			{
				updateBullet(gs.p1.ammo[i], gs.p1, gs.p2);
			}
			if (gs.p2.ammo[i].active)
			{
				updateBullet(gs.p2.ammo[i], gs.p1, gs.p2);
			}
		}

		updatePlayer(gs.p1);
		updatePlayer(gs.p2);
	}


	//for (int i = 0; i < Player::MAX_AMMO_COUNT; ++i)
	//{
	//	if (p1.ammo[i].active)
	//	{
	//		drawBullet(p1.ammo[i]);
	//	}
	//	if (p2.ammo[i].active)
	//	{
	//		drawBullet(p2.ammo[i]);
	//	}
	//}

	//drawPlayer(p1);
	//drawPlayer(p2);
	//drawScore(d, p1.score, p2.score);

	//if (p1.score >= 15)
	//{
	//	gameOver = true;
	//	drawWin(d);
	//}
	//if (p2.score >= 15)
	//{
	//	gameOver = true;
	//	drawWin2(d);
	//}
}

void drawGamestate(GameState &gs)
{
	if (!gs.gameOver)
	{


		for (int i = 0; i < Player::MAX_AMMO_COUNT; ++i)
		{
			if (gs.p1.ammo[i].active)
			{
				drawBullet(gs.p1.ammo[i]);
			}
			if (gs.p2.ammo[i].active)
			{
				drawBullet(gs.p2.ammo[i]);
			}
		}

		drawPlayer(gs.p1);
		drawPlayer(gs.p2);
		drawScore(gs.d, gs.p1.score, gs.p2.score);

		if (gs.p1.score >= 15)
		{
			gs.gameOver = true;
			drawWin(gs.d);
		}
		if (gs.p2.score >= 15)
		{
			gs.gameOver = true;
			drawWin2(gs.d);
		}
	}
}


