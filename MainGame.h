#pragma once

// MainGame.h 
// ----------
// Used in the main game

// ----------- LIBTRARY USED -----------
#include <raylib.h>
#include <raymath.h>
#include <vector>

#include "Player.h"
#include "Common.h"
#include "UI.h"
#include "Assets.h"

#define WallSize 14
#define DoorSize 25

// -------------------- TIME FUNCTION --------------------
// In game time for EVERYTHING in Game
// -------------------------------------------------------
extern float TIME;
void TimeFunction();


// -------------------- ROOM FUNCTION --------------------
class Room {
public:
	void MakeRoom(Vector2 Position, Color Normal, Color Hover, Color Click , const char *RoomName, State NewState);
	void MakeRoom_E(Vector2 Position, Color Normal, Color Click,  const char* RoomName, State NewState);
	void Bathroom();
	void OutSideRoom();
};
extern Room room;


// -------------------- MINIGAME: REACTION GAME IN BATHROOM --------------------
extern Rectangle Base;
extern Rectangle Moving;
extern Rectangle Target;

void MakeBathroomGame(Color B_Color, Color B_Hit, Color M_Color, Color M_Hit, Color T_Color, Color T_Hit);


// -------------------- OUTSIDE THE ROOM --------------------
// Make Map and Navigation

extern Rectangle Wall[WallSize];
extern Rectangle Door[DoorSize];

void MakeMap_OutsideRoom();
