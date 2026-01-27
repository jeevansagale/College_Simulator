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

void MakeButton(Rectangle Btn,
	Color Normal,
	Color Touch,
	Color Click,
	const char* BtnName,
	State NextState,
	Font FontFamily,
	int Size);


void MakeTitle(const char* Title);