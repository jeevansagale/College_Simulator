#include "MainGame.h"

Room room;

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


void Room::Bathroom() {
	MakeButton({ 200 , 200 , 200 , 50 }, YELLOW, GREEN, RED, "Return", PreviousState, Pixel, 32);
}


void Room::OutSideRoom() {
	
}