//A Simple College Simulator using Raylib and C++

#include <iostream>
#include <vector>
#include <string>
#include <raylib.h>
#include <raymath.h>

//-------- Game Libraries ---------//
#include "Common.h"
#include "UI.h"
#include "Assets.h"
#include "MainGame.h"
#include "Player.h"


//========== Function Declaration ==========
void Credits_Function();
void Return();

//========== Main Function ==========

int main() {
	//Initialize game elements like screen window and FPS
	InitWindow(Screen_Width, Screen_Height, "College Simulator");                          
	SetTargetFPS(60);
	SetExitKey(KEY_NULL);  //Disabled default Exit key [Esc]

	// Loading Textures, Fonts, Images, Sounds and Music from Assets.h
	LoadFonts();
	LoadTextures();

	//========== MAIN GAME LOOP ==========
	while (!WindowShouldClose()) {           
		MousePosition = GetMousePosition();     
		
		BeginDrawing();
		ClearBackground(RAYWHITE);

		//-------------------------------------In Main Menu of the Game----------------------------------//
		if (CurrentState == MENU) {
			DrawTextureEx(Background_Menu, { 0,0 }, 0, 0.286, WHITE);
			MakeTitle("College Simulator");      //Title Function from UI.h

			//========== Buttons in the Main Menu ==========
			MakeButton({ 400 , 300 , 250 , 50 }, GREEN, GRAY, RED, "START", CHOOSENAME , Pixel , 32);
			MakeButton({ 400 , 400 , 250 , 50 }, YELLOW, GRAY, GOLD, "CREDITS", CREDITS, Pixel, 32);
			MakeButton({ 400 , 500 , 250 , 50 }, GRAY, LIGHTGRAY, DARKGRAY, "SETTING", SETTING, Pixel, 32);
			MakeButton({ 400 , 600 , 250 , 50 }, RED, GRAY, DARKGRAY, "EXIT", EXIT, Pixel, 32);

			Return();
		}

		//========== State: Choose Player Name ==========
		else if (CurrentState == CHOOSENAME) {
			DrawTextureEx(Background_Menu, { 0,0 }, 0, 0.286, WHITE);
			ChooseName();
			Return();
		}

		//========== State: Choose Gender ==========
		else if (CurrentState == CHOOSEGENDER) {
			DrawTextureEx(Background_Menu, { 0,0 }, 0, 0.286, WHITE);
			ChooseGender();
			Return();
		}

		//========== State: Choose Subject[Language] ==========
		else if (CurrentState == CHOOSELANGUAGE) {
			DrawTextureEx(Background_Menu, { 0,0 }, 0, 0.286, WHITE);
			ChooseLanguage();
			Return();
		}

		//========== State: Hostel Room ==========
		else if (CurrentState == HOSTELROOM) {
			Bar_Make();
			room.MakeRoom({500 , 500} , GRAY , BLACK , RED , "BATHROOM" , BATHROOM);
			room.MakeRoom({ 700 , 300 }, GRAY, BLACK, GREEN, "OUTSIDE", OUTSIDEROOM);
			room.MakeRoom({ 900 , 650 }, BLACK, LIGHTGRAY, MAROON , "PHONE" , PHONE);
		}

		//========== State: Hostel Bathroom ==========
		else if (CurrentState == BATHROOM) {
			room.Bathroom();
		}

		//-------------------- CREDITS --------------------
		else if (CurrentState == CREDITS) {
			Credits_Function();
			Return();
		}

		//-------------------- EXIT --------------------
		else if (CurrentState == EXIT) {
			break;
		}

		BlackScreen_Update(BLACK);       //Updates the Blackscreen between states

		EndDrawing();
	}

	// UnLoading Textures, Sound, Music, Fonts, Images
	UnLoadFonts();
	UnLoadTexures();

	CloseWindow();
	return 0;
}

//=========================================================================================================\\

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