#include "game.h"
#include "sfwdraw.h"
#include <iostream>
#include <cstdio>
#include "Player.h"
#include "bullet.h"
#include "constdecl.h"

class GameState
{
private:
	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned r = sfw::loadTextureMap("./res/background.jpg");
	unsigned u = sfw::loadTextureMap("./res/crosshair.png");
	Player p1, p2;
	Rectangle playerRect;
	bool gameOver = false;
	float timer = 2;
public:
	void init();
	void update();
	void drawRound();
	APP_STATE next();
	void play();
};
