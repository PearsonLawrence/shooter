#pragma once
#include "constdecl.h"

class Splash
{
	int font;
	float timer;
public:
	//called on startup
	void init(int a_font);

	//called on activation
	void play();

	//called on update
	void draw();
	void step();

	APP_STATE next();

};