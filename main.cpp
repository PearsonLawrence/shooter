#include "game.h"
#include "sfwdraw.h"
#include "Gamestate.h"
void main()
{
	srand(time(0));
	sfw::initContext(800, 600, "Shooter");

	GameState gs;
	createGamestate(gs);
	sfw::setBackgroundColor(BLACK);

	while (sfw::stepContext())
	{
		updateGamestate(gs);

		drawGamestate(gs);
	}
	sfw::termContext();
}