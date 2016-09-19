
#include "Gamestate.h"
#include <cstdio>
#include "sfwdraw.h"
#include "constdecl.h"
#include "splash.h"
#include "depart.h"
#include "option.h"
#include "next.h"
void main()
{
	sfw::initContext(1890, 950, "NSFW Draw");
	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned r = sfw::loadTextureMap("./res/background.jpg");
	unsigned u = sfw::loadTextureMap("./res/crosshair.png");
	unsigned font = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	GameState gs;

	//gs.init();
	Option option;
	Depart depart;
	Splash splash;
	Next next;

	option.init(font);

	splash.init(font);

	depart.init(font);

	next.init(font);
	bool quit = false;

	APP_STATE state = ENTER_SPLASH;
	while (sfw::stepContext() && !quit)
	{
		switch (state)
		{
		case ENTER_OPTION:
			option.play();

		case OPTION:
			option.step();
			option.draw();
			state = option.next();
			break;

		case ENTER_SPLASH:
			splash.play();

		case SPLASH:
			splash.step();
			splash.draw();
			state = splash.next();
			break;
		case ENTER_ACTION:
			gs.init();

		case ACTION:
			sfw::drawTexture(r, 10, 980, 1870, 995, 0, false, 0, RED);
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
		case ENTER_DEPART:
			depart.play();

		case DEPART:
			depart.step();
			depart.draw();
			state = depart.next();
			break;

		case TERMINATE: quit = true;
		}
	}

	sfw::termContext();
}
