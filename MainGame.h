#pragma once

#include <raylib.h>
#include <raymath.h>
#include <vector>

#include "Player.h"
#include "Common.h"
#include "UI.h"
#include "Assets.h"

void HostelRoom();
class Room {
public:
	bool Entered;
	Room();
	void MakeRoom(Vector2 Position, Color Normal, Color Hover, Color Click , const char *RoomName, State NewState);
};
extern Room room;
