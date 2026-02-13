#pragma once

// Common.h
// ----------
// Declaring Common Elements and variables in here
// Used throughout the Game files

// ---------- Other Game Libraries ----------
#include "Assets.h"
#include <raylib.h>
#include <raymath.h>

// ---------- Screen Dimensions ----------
#define Screen_Height 900
#define Screen_Width 1020

// ---------- GAME STATES ----------
enum State {
	// ---------- MENU ----------
	MENU ,  
	CREDITS , 
	SETTING ,
	EXIT ,
	
	// ---------- INPUT INFO ----------
	CHOOSENAME , 
	CHOOSEGENDER , 
	CHOOSELANGUAGE , 
	
	// ---------- MAINGAME ----------
	HOSTELROOM , 
	BATHROOM ,
	PHONE , 
	OUTSIDEROOM ,
	CAMPUS , 
	CLASS , 
	CANTEEN 
};

extern State CurrentState;   // CURRENTSTATE of the game
extern State PendingState;   // PENDINGSTATE of the game
extern State PreviousState;  // PREVIOUSSTATE of the game

extern Vector2 MousePosition;   // Vector of Mouse positions [x,y] co-ordinates
