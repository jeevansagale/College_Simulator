#include "UI.h"

Title title = {
	0 ,
	-500 ,
	100
};

BlackScreen blackscreen = {
	0 ,
	0
};

void MakeButton(Rectangle Btn,
	Color Normal,
	Color Touch,
	Color Click,
	const char* BtnName,
	State NextState , 
	Font FontFamily , 
	int Size) {
	
	bool Check = CheckCollisionPointRec(MousePosition, Btn);
	float dt = GetFrameTime();

	Vector2 TxtSize = MeasureTextEx(FontFamily , BtnName, Size , 2);
	Vector2 Location = { Btn.x + (Btn.width - TxtSize.x) / 2 , 
		                 Btn.y + (Btn.height - TxtSize.y) / 2 };
	Vector2 Original = { Btn.width , Btn.height };

	if (Check) { Normal = Touch; }
	if (Check && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) { Normal = Click; }
	if (Check && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) { StartBlackScreen(NextState); }

	if (Check) {
		Btn.width += dt * 100;
		Btn.height += dt * 100;
	}
	else {
		Btn.width -= dt * 100;
		Btn.height -= dt * 100;
	}

	Btn.width = Clamp(Btn.width, Original.x, Original.x + 40);
	Btn.height = Clamp(Btn.height, Original.y, Original.y + 20);

	DrawRectangleRec(Btn, Normal);
	DrawTextEx(FontFamily, BtnName , Location, Size, 2, BLACK);
}


void MakeTitle(const char* Title) {
	float dt = GetFrameTime();

	title.DirX += dt * 300;
	title.Alpha += dt;

	Vector2 Location = { title.DirX , title.DirY };

	if (title.DirX >= 100) { title.DirX = 100; title.DirX = Clamp(title.DirX, -600, 100); }
	if (title.Alpha >= 1) { title.Alpha = 1; }

	DrawTextEx(Thick_Pixel, Title, Location, 64, 2, Fade(BLACK , title.Alpha));
}


void StartBlackScreen(State Next) {
	auto& BS = blackscreen;
	if (BS.Dir != 0) return;
	PendingState = Next;
	BS.Dir = 1;
}


void BlackScreen_Update(Color color) {
	auto& BS = blackscreen;
	float dt = GetFrameTime();

	if (BS.Dir != 0) {
		BS.Alpha += dt * BS.Dir * 1.5f;

		if (BS.Alpha >= 1.0f) {
			BS.Alpha = 1;
			CurrentState = PendingState;
			BS.Dir = -1;
		}

		if (BS.Alpha <= 0) {
			BS.Alpha = 0;
			BS.Dir = 0;
		}
		
		DrawRectangle(0, 0, Screen_Width, Screen_Height, Fade(color, BS.Alpha));
	}
}
