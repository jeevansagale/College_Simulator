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
	void MakeRoom(Vector2 Position, Color Normal, Color Hover, Color Click , const char *RoomName, State NewState);
	void Bathroom();
	void OutSideRoom();
};
extern Room room;
