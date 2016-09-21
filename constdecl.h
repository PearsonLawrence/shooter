#pragma once
enum APP_STATE
{
	TERMINATE,
	ENTER_SPLASH, SPLASH, //intro
	ENTER_DEPART, DEPART, // say goodbye
	ENTER_OPTION, OPTION, // main menu
	ENTER_ACTION, ACTION,
	ENTER_NEXT, NEXT,
	ENTER_LOAD, LOAD,
};


// States will have 4 properties:
// initialization
//called once
//activation
//setting up the state 
//update
//draw
//transition