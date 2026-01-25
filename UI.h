#pragma once

#include "Common.h"
#include "Assets.h"
#include <raylib.h>
#include <raymath.h>

void MakeButton(Rectangle Btn,
	Color Normal,
	Color Touch,
	Color Click,
	const char* BtnName,
	State NextState,
	Font FontFamily,
	int Size);


void MakeTitle(const char* Title);