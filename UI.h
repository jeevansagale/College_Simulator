#pragma once

#include "Common.h"
#include "Assets.h"
#include <raylib.h>
#include <raymath.h>

struct Title {
	float Alpha;
	float DirX;
	float DirY;
};
extern Title title;

struct BlackScreen {
	float Alpha;
	int Dir;
};
extern BlackScreen blackscreen;

void MakeButton(Rectangle Btn,
	Color Normal,
	Color Touch,
	Color Click,
	const char* BtnName,
	State NextState,
	Font FontFamily,
	int Size);


void MakeTitle(const char* Title);

void StartBlackScreen(State Next);
void BlackScreen_Update(Color color);