
#include "Gamestate.h"
#include <cstdio>
#include "sfwdraw.h"
#include "constdecl.h"
#include "splash.h"
#include "depart.h"
#include "option.h"
#include "next.h"
#include "load.h"
void main()
{
	sfw::initContext(1890, 950, "NSFW Draw");
	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned r = sfw::loadTextureMap("./res/Eaarth.jpg");
	unsigned u = sfw::loadTextureMap("./res/spaceship.png");
	unsigned font = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned s = sfw::loadTextureMap("./res/1.png");
	unsigned p = sfw::loadTextureMap("./res/start.jpg");
	unsigned t = sfw::loadTextureMap("./res/lose.jpg");
	unsigned o = sfw::loadTextureMap("./res/option.jpg");
	unsigned n = sfw::loadTextureMap("./res/orb.png");
	unsigned v = sfw::loadTextureMap("./res/enemy.png");
	unsigned z = sfw::loadTextureMap("./res/deep.jpg");
	unsigned c = sfw::loadTextureMap("./res/blackholew.png");
	GameState gs;

	//gs.init();
	Option option;
	Depart depart;
	Splash splash;
	Next next;
	Load load;

	option.init(font);

	splash.init(font);

	depart.init(font);

	next.init(font);

	load.init(font);
	bool quit = false;

	APP_STATE state = ENTER_SPLASH;

	
	while (sfw::stepContext() && !quit)
	{
		switch (state)
		{
		case ENTER_OPTION:
			option.play();

		case OPTION:
			sfw::drawTexture(o, 0, 950, 1890, 950, 0, false, 0);
			option.step();
			option.draw();
			state = option.next();
			break;

		case ENTER_SPLASH:
			splash.play();

		case SPLASH:
			sfw::drawTexture(p, 0, 950, 1890, 950, 0, false, 0);
			splash.step();
			splash.draw();
			state = splash.next();
			break;
		case ENTER_ACTION:
			gs.init();

		case ACTION:
			sfw::drawTexture(r, 0, 980, 1890, 995, 0, false, 0);
			gs.update();
			gs.drawRound();
			state = gs.next();
			break;

		case ENTER_NEXT:
			next.play();

		case NEXT:
			gs.drawRound();
			next.step();
			next.draw();
			state = next.next();
			break;
		case ENTER_LOAD:
				load.play();

		case LOAD:
			sfw::drawTexture(s, 0, 980, 1890, 1005, 0, false, 0, WHITE);
			load.step();
			load.draw();
			state = load.load();
			break;
		case ENTER_DEPART:
			depart.play();
		
		case DEPART:
			sfw::drawTexture(z, 0, 950, 1890, 950, 0, false, 0);
			depart.step();
			depart.draw();
			state = depart.next();
			break;

		case TERMINATE: quit = true;
		}
	}

	sfw::termContext();
}
