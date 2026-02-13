#include "UI.h"

// ---------- Title ----------
Title title = {
	0 ,            // Alpha 
	-500 ,         // X - cord
	100            // Y - cord
};


// ---------- BLACKSCREEN ----------
BlackScreen blackscreen = {
	0 ,            // Alpha
	0              // Direction [Initial zero for not moving]
};


// ---------- Button ----------
void MakeButton(Rectangle Btn,
	Color Normal,
	Color Touch,
	Color Click,
	const char* BtnName,
	State NextState , 
	Font FontFamily , 
	int Size) {
	
	bool Check = CheckCollisionPointRec(MousePosition, Btn);      // Checks Collision between btn and cursor
	float dt = GetFrameTime();     // Gets frame rate for smoother flow 

	Rectangle Original = Btn;

	if (Check) { Normal = Touch; }
	if (Check && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) { Normal = Click; }
	if (Check && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) { PreviousState = NextState; StartBlackScreen(NextState); }

	// ---------- Button Size grow and shrink animation ----------
	if (Check) {
		Btn.width += dt * 100;
		Btn.height += dt * 100;
		Btn.x -= dt * 50;
		Btn.y -= dt * 50;
	}
	else {
		Btn.width -= dt * 100;
		Btn.height -= dt * 100;
		Btn.x += dt * 50;
		Btn.y += dt * 50;
	}

	// Clamping the width and height of the button
	Btn.width = Clamp(Btn.width, Original.width, Original.width + 40);
	Btn.height = Clamp(Btn.height, Original.height, Original.height + 20);

	// Calculating Center of the rectangle to put text 
	Vector2 TxtSize = MeasureTextEx(FontFamily, BtnName, Size, 2);
	Vector2 Location = { Btn.x + (Btn.width - TxtSize.x) / 2 ,
						 Btn.y + (Btn.height - TxtSize.y) / 2 };

	// Drawing the rectangle [ BUTTON ]
	DrawRectangleRec(Btn, Normal);
	DrawRectangleLinesEx(Btn, 3.0f, BLACK);
	DrawTextEx(FontFamily, BtnName , Location, Size, 2, BLACK);
}


// ---------- TITLE ANIMATION ----------
void MakeTitle(const char* Title) {
	float dt = GetFrameTime();

	title.DirX += dt * 300;
	title.Alpha += dt;

	Vector2 Location = { title.DirX , title.DirY };

	if (title.DirX >= 100) { title.DirX = 100; title.DirX = Clamp(title.DirX, -600, 100); }
	if (title.Alpha >= 1) { title.Alpha = 1; title.Alpha = Clamp(title.Alpha, 0, 1); }

	DrawTextEx(Thick_Pixel, Title, Location, 64, 2, Fade(BLACK , title.Alpha));
}


// ---------- BLACK SCREEN ----------
// which state does this take us
void StartBlackScreen(State Next) {
	auto& BS = blackscreen;
	if (BS.Dir != 0) return;
	PendingState = Next;
	BS.Dir = 1;
}

// Updating the blackscreen after each state change
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


//========== Credits Function ==========
void Credits_Function() {
	//---------- Main Developer ---------------//
	DrawTextEx(Thick_Pixel, "Made by : ", { 30 , 30 }, 64, 2, BLACK);
	DrawTextEx(Thick_Pixel, "Jeevan Sagale ", { 50 , 100 }, 64, 2, BLACK);

	//---------- Idea Given by ----------------//
	DrawTextEx(Thick_Pixel, "Idea : ", { 30 , 200 }, 64, 2, BLACK);
	DrawTextEx(Thick_Pixel, "Pranav ", { 50 , 300 }, 64, 2, BLACK);

	//---------- Font found on ----------------//
	DrawTextEx(Pixel, "Font ", { 30 , 400 }, 32, 2, BLACK);
	DrawTextEx(Pixel, "From Google Fonts ", { 50 , 450 }, 32, 2, BLACK);

	//---------- Image found at --------------//
	DrawTextEx(Pixel, "Images ", { 30 , 500 }, 32, 2, BLACK);
	DrawTextEx(Pixel, "From Google", { 50 , 550 }, 32, 2, BLACK);

	Return();
}


//Resets Some Elements when Esc is pressed
void Return() {
	if (IsKeyPressed(KEY_ESCAPE)) {
		CurrentState = MENU;

		title.DirX = -500;         //Reset Titles position
		title.Alpha = 0;           //Resets Alpha[Transparency] of Title
		Clicked2 = true;           //Resets Name Choosing/Confirming Button

		for (int i = 0; i < 5; i++) {
			Clicked[i] = true;     //Resets Gender Choosing/Confirming Button
			Clicked1[i] = true;    //Resets Subject[Language] Button
		}
	}
}