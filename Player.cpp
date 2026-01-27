#include "Player.h"

Player player;
BarMake barmake[50];

bool Clicked2 = true;
bool Clicked1[5] = { true , true , true , true , true };
bool Clicked[5] = { true , true , true , true , true };

Player::Player(){
	Max_Attendance = 100;               //Max attendance
    Max_Stress = 100;                   //Max Stress
	Max_Reputation = 100;               //Max Reputation
	Max_ToiletMeter = 100;              //Max Toilet progress
	Max_LoveMeter = 100;                //Max Lover progress
	Max_SleepMeter = 100;               //Max Sleep progress [Need to sleep]

	Gender = "";                        //Default Gender
	Name = "";                          //Default Name
	Subject = "";                       //Default Sibject

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

	if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_KP_ENTER)) { Clicked2 = false; }
	if (!Clicked2) { MakeButton({ 200 , 200 , 200 , 50 }, YELLOW, GRAY, GOLD, "Confirm", CHOOSEGENDER, Pixel, 32); }
}


void ChooseGenderBox(Rectangle Box, Color BoxColor, Color BoxHover, Color BoxClick, int Index, const char* Gender) {
	bool Check = CheckCollisionPointRec(MousePosition, Box);

	Vector2 TxtSize = MeasureTextEx(Thick_Pixel, Gender, 32, 2);
	Vector2 Location = { Box.x + (Box.width - TxtSize.x) / 2 , Box.y + (Box.height - TxtSize.y) / 2 };

	if (Check) { BoxColor = BoxHover; }

	if (Check && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { Clicked1[Index] = !Clicked1[Index]; player.Gender = Gender; Clicked1[0] = false; }

	if (!Clicked1[Index]) { BoxColor = BoxClick; }

	if (!Clicked1[Index]) { MakeButton({200 , 200 , 200 , 50}, YELLOW, GRAY, GOLD, "Confirm", CHOOSELANGUAGE, Pixel, 32); }

	DrawRectangleRec(Box, BoxColor);
	DrawTextEx(Thick_Pixel, Gender, Location, 32, 2, BLACK);

	if (Index == 1 && !Clicked1[Index]) { Clicked1[2] = true; }
	if (Index == 2 && !Clicked1[Index]) { Clicked1[1] = true; }
}


void ChooseGender() {
	ChooseGenderBox({ 500 , 350 , 200 , 50 }, GRAY, DARKGRAY, GREEN, 1, "MALE");
	ChooseGenderBox({ 300 , 350 , 200 , 50 }, GRAY, DARKGRAY, GREEN, 2, "FEMALE");
}


void ChooseLanguageBox(Rectangle Box, Color BoxColor, Color BoxHover, Color BoxClick , int Index , const char *Language) {
	bool Check = CheckCollisionPointRec(MousePosition, Box);
	Vector2 TxtSize = MeasureTextEx(Pixel, Language, 32, 2);
	Vector2 Location = { Box.x + (Box.width - TxtSize.x) / 2 , Box.y + (Box.height - TxtSize.y) / 2 };

	if (Check) { BoxColor = BoxHover; }

	if (Check && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { Clicked[Index] = !Clicked[Index]; player.Subject = Language; Clicked[0] = false; }

	if (!Clicked[Index]) { BoxColor = BoxClick; }

	if (!Clicked[0]) { MakeButton({ 350 , 700 , 200 , 50 }, YELLOW, GRAY, GOLD, "Confirm", START, Pixel, 32); }

	DrawRectangleRec(Box, BoxColor);
	DrawTextEx(Pixel, Language, Location, 32, 2 , BLACK);

	if (Index == 1 && !Clicked[Index]) { Clicked[2] = Clicked[3] = Clicked[4] = true; }
	if (Index == 2 && !Clicked[Index]) { Clicked[1] = Clicked[3] = Clicked[4] = true; }
	if (Index == 3 && !Clicked[Index]) { Clicked[1] = Clicked[2] = Clicked[4] = true; }
	if (Index == 4 && !Clicked[Index]) { Clicked[1] = Clicked[2] = Clicked[3] = true; }
}


void ChooseLanguage() {
	ChooseLanguageBox({ 200 , 200 , 200 , 50 }, DARKGRAY, LIGHTGRAY, RED, 1, "Enlish");
	ChooseLanguageBox({ 200 , 300 , 200 , 50 }, DARKGRAY, LIGHTGRAY, GREEN, 2, "German");
	ChooseLanguageBox({ 780 , 200 , 200 , 50 }, DARKGRAY, LIGHTGRAY, BLUE, 3, "BST");
	ChooseLanguageBox({ 780 , 300 , 200 , 50 }, DARKGRAY, LIGHTGRAY, PINK, 4, "Japanese");
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
