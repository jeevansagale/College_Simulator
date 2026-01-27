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
	CHOOSENAME , 
	CHOOSEGENDER , 
	CHOOSELANGUAGE , 
	HOSTELROOM 
};
extern State CurrentState;
extern State PendingState;

extern Vector2 MousePosition;