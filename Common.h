#pragma once

#include "Assets.h"
#include <raylib.h>
#include <raymath.h>

#define Screen_Height 900
#define Screen_Width 1020

enum State {
	MENU , 
	START , 
	CREDITS , 
	SETTING ,
	EXIT ,
	WAKE_UP  
};
extern State CurrentState;

extern Vector2 MousePosition;

struct Title {
	float Alpha;
	float DirX;
	float DirY;
};
extern Title title;