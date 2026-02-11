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


// -------------------- ROOM FUNCTION --------------------
class Room {
public:
	void MakeRoom(Vector2 Position, Color Normal, Color Hover, Color Click , const char *RoomName, State NewState);
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
void MakeMap_OutsideRoom();
