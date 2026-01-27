#pragma once

#include <raylib.h>
#include <raymath.h>
#include <vector>

struct Eyes {
	float UpperEye;
	float LowerEye;
	float Alpha;
	int dirUP;
	int dirDOWN;
	float Size;
};
extern Eyes eyes;


void EyesOpen();
void HostelRoom();

