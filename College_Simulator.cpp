//A Simple College Simulator using Raylib and C++


#include <iostream>
#include <vector>
#include <string>
#include <raylib.h>
#include <raymath.h>

#include "Common.h"
#include "UI.h"
#include "Assets.h"
#include "MainGame.h"
#include "Player.h"

void Credits_Function();
void Return();

int main() {
	InitWindow(Screen_Width, Screen_Height, "College Simulator");
	SetTargetFPS(60);
	SetExitKey(KEY_NULL);

	LoadFonts();
	LoadTextures();

	while (!WindowShouldClose()) {
		MousePosition = GetMousePosition();
		
		BeginDrawing();
		ClearBackground(RAYWHITE);

		if (CurrentState == MENU) {
			DrawTextureEx(Background_Menu, { 0,0 }, 0, 0.286, WHITE);
			MakeTitle("College Simulator");

			MakeButton({ 400 , 300 , 250 , 50 }, GREEN, GRAY, RED, "START", CHOOSENAME , Pixel , 32);
			MakeButton({ 400 , 400 , 250 , 50 }, YELLOW, GRAY, GOLD, "CREDITS", CREDITS, Pixel, 32);
			MakeButton({ 400 , 500 , 250 , 50 }, GRAY, LIGHTGRAY, DARKGRAY, "SETTING", SETTING, Pixel, 32);
			MakeButton({ 400 , 600 , 250 , 50 }, RED, GRAY, DARKGRAY, "EXIT", EXIT, Pixel, 32);

			Return();
		}

		else if (CurrentState == CHOOSENAME) {
			ChooseName();
			Return();
		}

		else if (CurrentState == CHOOSEGENDER) {
			ChooseGender();
			Return();
		}

		else if (CurrentState == CHOOSELANGUAGE) {
			ChooseLanguage();
			Return();
		}

		else if (CurrentState == START) {
			EyesOpen();
		}

		else if (CurrentState == CREDITS) {
			Credits_Function();
			Return();
		}

		else if (CurrentState == EXIT) {
			break;
		}

		EndDrawing();
	}

	UnLoadFonts();
	UnLoadTexures();
	CloseWindow();
	return 0;
}


void Credits_Function() {
	DrawTextEx(Thick_Pixel, "Made by : ", { 30 , 30 }, 64, 2, BLACK);
	DrawTextEx(Thick_Pixel, "Jeevan Sagale ", { 50 , 100 }, 64, 2, BLACK);

	DrawTextEx(Thick_Pixel, "Idea : ", { 30 , 200 }, 64, 2, BLACK);
	DrawTextEx(Thick_Pixel, "Pranav ", { 50 , 300 }, 64, 2, BLACK);

	DrawTextEx(Pixel, "Font ", { 30 , 400 }, 32, 2, BLACK);
	DrawTextEx(Pixel, "From Google Fonts ", { 50 , 450 }, 32, 2, BLACK);

	DrawTextEx(Pixel, "Images ", { 30 , 500 }, 32, 2, BLACK);
	DrawTextEx(Pixel, "From Google", { 50 , 550 }, 32, 2, BLACK);

	Return();
}


void Return() {
	if (IsKeyPressed(KEY_ESCAPE)) {
		CurrentState = MENU;
		
		title.DirX = -500;
		title.Alpha = 0;
		Clicked2 = true;
		for (int i = 0; i < 5; i++) {
			Clicked[i] = true;
			Clicked1[i] = true;
		}
	}
}