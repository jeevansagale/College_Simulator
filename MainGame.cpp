#include "MainGame.h"

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

void MakeMap_OutsideRoom() {
	ClearBackground(LIGHTGRAY);
	float dx = 0;
	float dy = 0;
	bool HitX = false;
	bool HitY = false;

	// ---------- PLAYER MOVEMENT ----------
	if (IsKeyDown(KEY_W)) { dy -= GetFrameTime() * 200; }
	if (IsKeyDown(KEY_S)) { dy += GetFrameTime() * 200; }
	if (IsKeyDown(KEY_A)) { dx -= GetFrameTime() * 200; }
	if (IsKeyDown(KEY_D)) { dx += GetFrameTime() * 200; }

	// ---------- WALL ----------
	Rectangle Wall[2] = { {300 , 10 , 40 , 900} ,       // Left wall
						  {600 , 10 , 40 , 900}         // Right wall
	};
	Rectangle Door[1] = {
		{300 , 100 , 70 , 100}

	};
	// ---------- DRAW WALL ----------
	for (int i = 0; i < 2; i++) {
		DrawRectangleRec(Wall[i], RED);
	}
	for (int i = 0; i < 1; i++) {
		DrawRectangleRec(Door[i], BLACK);
	}

	// ---------- X - AXIS MOVEMENT ----------
	player.Position.x += dx;
	Rectangle PlayerX = { player.Position.x, player.Position.y, 50, 50 };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 1; j++) {
			if (CheckCollisionRecs(PlayerX, Wall[i]) || CheckCollisionRecs(PlayerX, Door[j])) {
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
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 1; j++) {
			if (CheckCollisionRecs(PlayerY, Wall[i]) || CheckCollisionRecs(PlayerY, Door[j])) {
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
}