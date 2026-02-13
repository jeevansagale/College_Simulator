#include "MainGame.h"


// -------------------- TIME FUNCTION --------------------
float TIME = 480.0f;
void TimeFunction() {
	TIME += GetFrameTime();

	int Hour = (int)(TIME / 60) % 24;
	int Min = (int)TIME % 60;
	int Sec = (int)(TIME * 60) % 60;
	
	if (TIME >= 1440) {
		TIME = 0;
	}

	DrawTextEx(Thick_Pixel, TextFormat("Time : %02d:%02d ", Hour, Min), { 450 , 10 }, 32, 2, BLACK);
}


// -------------------- ROOM FUNCTIONS --------------------
Room room;

// Making the room
void Room::MakeRoom(Vector2 Position , Color Normal , Color Hover , Color Click, const char* RoomName , State NewState) {
	State PreviousState;
	Vector2 TxtSize = MeasureTextEx(Pixel, RoomName, 32, 2);
	Rectangle TxtRec = {
		Position.x - (TxtSize.x / 2) , Position.y - (TxtSize.y / 2) ,
		TxtSize.x , TxtSize.y
	};

	bool Check = CheckCollisionPointRec(MousePosition , TxtRec);
	if (Check) { Normal = Hover; }
	PreviousState = CurrentState;
	if (Check && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) { Normal = Click; }
	if (Check && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) { PreviousState = NewState; StartBlackScreen(NewState); }

	DrawTextEx(Pixel, RoomName, { TxtRec.x , TxtRec.y }, 32, 2, Normal);
}

void Room::MakeRoom_E(Vector2 Position, Color Normal, Color Click,  const char* RoomName, State NewState) {
	State PreviousState;
	Vector2 TxtSize = MeasureTextEx(Pixel, RoomName, 16, 2);
	Rectangle TxtRec = {
		Position.x - (TxtSize.x / 2) , Position.y - (TxtSize.y / 2) ,
		TxtSize.x , TxtSize.y
	};

	float PlayerPosition = Vector2Distance(Position, player.Position);

	if (IsKeyDown(KEY_E)) { Normal = Click; }

	if (PlayerPosition <= 100.0f) {
		if (IsKeyReleased(KEY_E)) { PreviousState = NewState; StartBlackScreen(NewState); }
		DrawTextEx(Pixel, RoomName, { TxtRec.x , TxtRec.y }, 32, 2, Normal);
	}
}


// -------------------- BATHROOM GAME --------------------
// --------------------
// MINIGAME: Reaction time game 
// Reduces toilet meter and if failed increases player stress

Rectangle Base = { 300 , 450 , 600 , 100 };
Rectangle Moving = { 300 , 450 , 50 , 100 };
Rectangle Target = { 400 , 450 , 50 , 100 };

void MakeBathroomGame(Color B_Color, Color B_Hit, Color M_Color, Color M_Hit, Color T_Color, Color T_Hit) {
	float dt = GetFrameTime();
	static int dir = 1;
	static float Timer = 0.0f;
	static bool hit = false;
	static bool change = false;
    
	Moving.x += dt * 300 * dir;
	if (Moving.x >= 850) { dir = -1; }
	else if (Moving.x <= 300) { dir = 1; }

	if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
		if (CheckCollisionRecs(Moving, Target)) {
			Timer = 0.3f;
			hit = true;
			change = true;
		}
	}

	if (Timer >= 0.0f) {
		Timer -= dt;
		if (Timer <= 0.0f) {
			hit = false;
		}
	}

	if (change) {
		Target.x = (float)(GetRandomValue(300, 850) + 50);
		player.ToiletMeter += 5;
		player.Stress += 5;
		change = false;
	}


	DrawRectangleRec(Base, hit ? B_Color : B_Hit);
	DrawRectangleRec(Target, hit ? T_Color : T_Hit);
	DrawRectangleRec(Moving, hit ? M_Color : M_Hit);
}


void Room::Bathroom() {
	MakeButton({ 200 , 200 , 200 , 50 }, YELLOW, GREEN, RED, "Return", PreviousState, Pixel, 32);
	MakeBathroomGame(LIGHTGRAY, RED, Fade(GREEN, 0.5), DARKGREEN, RED, PINK);
}


// -------------------- OUTSIDE THE ROOM --------------------
// --------------------
// Navigate to go either : Classroom or Bunk or canteen

// ---------- WALL ----------
Rectangle Wall[WallSize] = {
	{300 , 10 , 40 , 1000} ,       // Lower Left wall
	{600 , 10 , 40 , 1000} ,       // Lower Right wall
	{300 , -1500 , 40 , 1100} ,    // Upper Left wall
	{600 , -1500 , 40 , 1600} ,    // Upper Right wall

	{600 , 1000 , 500 , 40} ,      // Lower Wall Right wall
	{-160 , 1000 , 500 , 40} ,     // Lower Wall Left wall
	{150 , 10 , 150 , 40} ,        // Lift wall
	{150 , -440 , 150 , 40} ,      // Lift wall
	{150 , -440 , 40 , 450} ,      // Wall connecting lift walls
	{150 , -220 , 190 , 40} ,      // Middle wall between two lifts

	{200 , -1500 , 100 , 40 } ,    // Upper Corrider 
	{200 , -1740 , 40 , 250 } ,    // -------------
	{200 , -1740 , 440 , 40 } ,    // -------------
	{600 , -1740 , 40 , 250}

};


Rectangle Door[DoorSize] = {
	// ---------- Lower Doors ----------
	{310 , 100 , 70 , 100} ,     // 0
	{310 , 300 , 70 , 100} ,     // 1
	{310 , 500 , 70 , 100} ,     // 2 , Player Room
	{310 , 700 , 70 , 100} ,     // 3
	{310 , 900 , 70 , 100} ,     // 4
	{560 , 100 , 70 , 100} ,     // 5
	{560 , 300 , 70 , 100} ,     // 6
	{560 , 500 , 70 , 100} ,     // 7
	{560 , 700 , 70 , 100} ,     // 8
	{560 , 900 , 70 , 100} ,     // 9

	// ---------- Upper Doors ----------
	{310 , -1400 , 70 , 100} ,   // 10
	{310 , -1200 , 70 , 100} ,   // 11
	{310 , -1000 , 70 , 100} ,   // 12
	{310 , -800 , 70 , 100} ,    // 13
	{310 , -600 , 70 , 100} ,    // 14
	{560 , -1400 , 70 , 100} ,   // 15
	{560 , -1200 , 70 , 100} ,   // 16
	{560 , -1000 , 70 , 100} ,   // 17
	{560 , -800 , 70 , 100} ,    // 18
	{560 , -600 , 70 , 100} ,    // 19

	// ---------- Lift Doors ----------
	{200 , -390 , 100 , 160} ,   // 20 , Main Lift 
	{200 , -170 , 100 , 170} ,   // 21 , Main Lift
	{250 , -1690 , 100 , 180} ,  // 22 , Upper Lift

	// ---------- Stairs ----------
	{550 , -390 , 150 , 190} ,   // 23
	{550 , -170 , 150 , 190}     // 24
};


void MakeMap_OutsideRoom() {
	ClearBackground(LIGHTGRAY);
	float dx = 0;
	float dy = 0;
	bool HitX = false;
	bool HitY = false;

	// ---------- PLAYER MOVEMENT ---------- [TEMP SPEED INCREASE , REDO AFTER TRIALS: 200]
	if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) { dy -= GetFrameTime() * 700; }
	if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) { dy += GetFrameTime() * 700; }
	if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) { dx -= GetFrameTime() * 700; }
	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) { dx += GetFrameTime() * 700; }


	// ---------- DRAW WALL ----------
	for (int i = 0; i < WallSize; i++) {
		DrawRectangleRec(Wall[i], RED);
	}
	for (int i = 0; i < DoorSize; i++) {
		DrawRectangleRec(Door[i], BLACK);
	}

	// ---------- X - AXIS MOVEMENT ----------
	player.Position.x += dx;
	Rectangle PlayerX = { player.Position.x, player.Position.y, 50, 50 };
	for (int i = 0; i < WallSize; i++) {
		if (CheckCollisionRecs(PlayerX, Wall[i])) {
			HitX = true;
			break;
		}
	}

	if (!HitX) {
		for (int j = 0; j < DoorSize; j++) {
			if (CheckCollisionRecs(PlayerX, Door[j])) {
				HitX = true;
				break;
			}
		}
	}
	
	if (HitX) {
		player.Position.x -= dx;  // Revert x position of player
	}

	// ---------- Y - AXIS MOVEMENT ----------
	player.Position.y += dy;
	Rectangle PlayerY = { player.Position.x, player.Position.y, 50, 50 };
	for (int i = 0; i < WallSize; i++) {
		if (CheckCollisionRecs(PlayerY, Wall[i])) {
			HitY = true;
			break;
		}
	}

	if (!HitY) {
		for (int j = 0; j < DoorSize; j++) {
			if (CheckCollisionRecs(PlayerY, Door[j])) {
				HitY = true;
				break;
			}
		}
	}
	
	if (HitY) {
		player.Position.y -= dy;  // Revert x position of player
	}

	// ---------- PLAYER ----------
	DrawRectangle(player.Position.x, player.Position.y, 50, 50, BLACK);
}


void Room::OutSideRoom() {
	MakeMap_OutsideRoom();
	room.MakeRoom_E({ Door[2].x , Door[2].y + 30 }, BLUE, PINK, "Enter Room", HOSTELROOM);
	room.MakeRoom_E({ Door[20].x + 25 , Door[20].y + 65 }, BLUE, PINK, "Enter Lift", CAMPUS);
	room.MakeRoom_E({ Door[21].x + 25 , Door[21].y + 65 }, BLUE, PINK, "Enter Lift", CAMPUS);
	room.MakeRoom_E({ Door[23].x , Door[23].y + 95 }, BLUE, PINK, "Stairs", CAMPUS);
	room.MakeRoom_E({ Door[24].x , Door[24].y + 95 }, BLUE, PINK, "Stairs", CAMPUS);
}