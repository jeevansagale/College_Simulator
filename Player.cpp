#include "Player.h"

Player player;
BarMake barmake[50];
bool clicked = true;
bool clicked1 = true;
bool clicked2 = true;

Player::Player(){
	Max_Attendance = 100;               //Max attendance
    Max_Stress = 100;                   //Max Stress
	Max_Reputation = 100;               //Max Reputation
	Max_ToiletMeter = 100;              //Max Toilet progress
	Max_LoveMeter = 100;                //Max Lover progress
	Max_SleepMeter = 100;               //Max Sleep progress [Need to sleep]

	Gender = "";                        //Default Gender
	Name = "";                          //Default Name

    Attendance = 100.0f;                //initial 100 attendance
	Stress = 0.0f;                      //Initial 0 stress
	Reputation = 10;                    //Initial 10 rep
	ToiletMeter = 0.0f;                 //Initial 0 toilet progress
	LoveMeter = 0.0f;                   //Initial 0 love progress
	SleepMeter = 0.0f;                  //Initial 0 i.e. No sleep needed
};

void MakeBar(Vector2 Position, int Index, float Percentage, Color Base, Color BarColor, Color Border , const char *BarName) {
	auto bar = &barmake[Index];
	bar[Index].BarH = 30;
	bar[Index].BarW = 200;
	bar[Index].BarNewW = Percentage * bar[Index].BarW;

	Vector2 TxtSize = MeasureTextEx(Pixel, BarName, 12, 2);
	Vector2 Location = { Position.x + (bar[Index].BarW - TxtSize.x) / 2 , Position.y + (bar[Index].BarH - TxtSize.y) / 2 };

	DrawRectangle(Position.x, Position.y, bar[Index].BarW, bar[Index].BarH, Base);
	DrawRectangle(Position.x, Position.y, bar[Index].BarNewW, bar[Index].BarH, BarColor);

	//Glowing border
	for (int i = 2; i > 0; i--) {
		DrawRectangleLinesEx({ Position.x, Position.y, bar[Index].BarW, bar[Index].BarH }, 2.0 * i , Fade(Border, 0.05f * i));
	}
	DrawRectangleLinesEx({ Position.x, Position.y, bar[Index].BarW, bar[Index].BarH }, 2.0f, Border);

	DrawTextEx(Pixel, BarName, Location, 12, 2, Fade(BLACK , 0.6f));
}

void Bar_Make() {
	MakeBar({ 10 , 10 }, 0, (player.Attendance / player.Max_Attendance), LIGHTGRAY, GOLD, YELLOW , "Attendace");
	MakeBar({ 10 , 50 }, 1, (player.Stress / player.Max_Stress), LIGHTGRAY, { 0, 0, 139, 250 }, Fade({ 0, 0, 139, 240 }, 0.2f) , "Stress");
	MakeBar({ 10 , 100 }, 2, (player.Reputation / player.Max_Reputation), LIGHTGRAY, LIME, Fade(GREEN, 0.2f) , "Reputation");
	MakeBar({ 780 , 10 }, 3, (player.ToiletMeter / player.Max_ToiletMeter), LIGHTGRAY, BROWN, Fade(DARKBROWN, 0.2f) , "Toilet");
	MakeBar({ 780 , 50 }, 4, (player.LoveMeter / player.Max_LoveMeter), LIGHTGRAY, PINK, Fade(RED, 0.2f) , "Love");
	MakeBar({ 780 , 100 }, 5, (player.SleepMeter / player.Max_SleepMeter), LIGHTGRAY, SKYBLUE, Fade(DARKBLUE, 0.2f) , "Sleep");
}

void Player::Attendance_Function() {

}

void Player::Stress_Function() {
	
}

void Player::Reputation_Function() {

}

void Player::Toilet_Function() {

}

void Player::Love_Function() {

}

void Player::Sleep_Function() {

}


void ChooseName() {
	char key = GetCharPressed();
	while (key > 0) {
		if ((key >= 32 && key <= 255) && player.Name.length() <= MAX_CHARACTER) {
			player.Name.push_back((char)key);
		}
		key = GetCharPressed();
	}

	if (IsKeyPressed(KEY_BACKSPACE) && !player.Name.empty()) {
		player.Name.pop_back();
	}

	DrawTextEx(Thick_Pixel, "Enter Name", { 200, 300 }, 32, 2 , BLACK);
	DrawTextEx(Thick_Pixel, player.Name.c_str(), { 300 , 350 }, 32, 2 , BLACK);
}

void ChooseGender(Color BoxColor1, Color BoxColor2, Color BoxColorClick1 , Color BoxColorClick2 , Color Click1 , Color Click2) {
	char Male[10] = "Boy";
	char FeMale[10] = "Girl";

	Rectangle Box1 = { 300 , 400 , 250 , 50 };
	Rectangle Box2 = { 600 , 400 , 250 , 50 };

	bool Check1 = CheckCollisionPointRec(MousePosition, Box1);
	bool Check2 = CheckCollisionPointRec(MousePosition, Box2);

	Vector2 TxtSize1 = MeasureTextEx(Thick_Pixel, Male, 32, 2);
	Vector2 TxtSize2 = MeasureTextEx(Thick_Pixel, FeMale, 32, 2);

	Vector2 Location1 = { Box1.x + (Box1.width - TxtSize1.x) / 2 , Box1.y + (Box1.height - TxtSize1.y) / 2 };
	Vector2 Location2 = { Box2.x + (Box2.width - TxtSize2.x) / 2 , Box2.y + (Box2.height - TxtSize2.y) / 2 };

	if (Check1) { BoxColor1 = BoxColorClick1; }
	if (Check2) { BoxColor2 = BoxColorClick2; }

	if (Check1 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { clicked1 = !clicked1; player.Gender = Male; clicked = false; }
	if (Check2 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { clicked2 = !clicked2; player.Gender = Male; clicked = false; }

	if(!clicked1){ BoxColor1 = Click1; }
	if(!clicked2){ BoxColor2 = Click2; }

	if(!clicked){ MakeButton({ 200 , 200 , 200 , 50 }, YELLOW, GRAY, GOLD, "Confirm", MENU, Pixel, 32); }


	DrawRectangleRec(Box1, BoxColor1);
	DrawRectangleRec(Box2, BoxColor2);

	DrawTextEx(Pixel, Male, Location1, 32, 2, BLACK);
	DrawTextEx(Pixel, FeMale, Location2, 32, 2, BLACK);
}

void ChooseLanguage() {

}