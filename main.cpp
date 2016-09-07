
#include "sfwdraw.h"
#include "gamee.h"
// using namespace std;
// using std::iostream;
// std::cout


void main()
{
	srand(time(0));
	sfw::initContext(800, 600, "Pongo");

	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned r = sfw::loadTextureMap("./res/background.jpg");
	unsigned u = sfw::loadTextureMap("./res/crosshair.png");

	float acc = 10;
	float acc2 = 10;

	Paddle p1 = createPaddle(20, 250, 100, 'W', 'S', BLUE),
		p2 = createPaddle(780, 250, 100, 'I', 'K', RED); // uninitialized!

	const int BALL_COUNT = 5;

	Ball b[BALL_COUNT];
	unsigned colors[] = { GREEN, YELLOW, WHITE };

	for (int i = 0; i < BALL_COUNT; i++)
	{
		b[i] = createBall(400, 300, randRange(5, 20), colors[randRange(0,2)]);
	}
	b[0].active = true;

	sfw::setBackgroundColor(BLACK);


	bool gameOver = false;
	while (sfw::stepContext())
	{
		// Input/Logic Step
		// - handle player input
		// - calculate new positions n' stuff

		if (!gameOver)
		{
			updateBall(b[0], p1, p2);
			updatePaddle(p1);
			updatePaddle(p2);

			if (p1.score >= 2 || p2.score >= 2)
			{
				b[1].active = true;
				//updateBall(b2, p1, p2);
				//drawBall(b2);
			}

			if (p1.score >= 3 || p2.score >= 3)
			{
				b[2].active = true;
				//updateBall(b3, p1, p2);
				//drawBall(b3);
			}
			if (p1.score >= 4 || p2.score >= 4)
			{
				b[3].active = true;
				//updateBall(b4, p1, p2);
				//drawBall(b4);
			}

			if (p1.score >= 5 || p2.score >= 5)
			{
				b[4].active = true;
				//updateBall(b7, p1, p2);
			}

			for (int i = 0; i < BALL_COUNT; ++i)
			{
				if (b[i].active)
					updateBall(b[i], p1, p2);
			}
		}
		
		// Draw
		for (int i = 0; i < BALL_COUNT; ++i)
		{
			if (b[i].active)
				drawBall(b[i]);
		}

		drawScore(d, p1.score, p2.score);

		if (p1.score >= 10)
		{
			gameOver = true;
			drawWin(d);
		}
		if (p2.score >= 10)
		{
			gameOver = true;
			drawWin2(d);
		}

	}

	sfw::termContext();
}