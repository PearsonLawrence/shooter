
#include "Gamestate.h"


void main()
{
	srand(time(0));
	sfw::initContext(800, 600, "Shooter");
	sfw::setBackgroundColor(BLACK);

	GameState gs;
	gs.init();
	
	while (sfw::stepContext())
	{
		gs.update();
		gs.drawRound();
	}
	sfw::termContext();
}