//A Simple College Simulator using Raylib and C++

#include <iostream>
#include <vector>
#include <string>
#include <raylib.h>
#include <raymath.h>

// -------- Game Libraries --------- //
#include "Common.h"
#include "UI.h"
#include "Assets.h"
#include "MainGame.h"
#include "Player.h"


// ========== Main Function ==========
int main() {
	// Initialize game elements like screen window and FPS
	InitWindow(Screen_Width, Screen_Height, "College Simulator");                          
	SetTargetFPS(60);
	SetExitKey(KEY_NULL);  //Disabled default Exit key [Esc]

	// Loading Textures, Fonts, Images, Sounds and Music from Assets.h
	LoadFonts();
	LoadTextures();


	// ========== Player Follow Camera ==========
	Camera2D cam = { 0 };
	cam.target = { player.Position.x , player.Position.y };
	cam.offset = { 510 , 450 };
	cam.zoom = 1.0f;
	cam.rotation = 0;


	// ========== MAIN GAME LOOP ==========
	while (!WindowShouldClose()) {           
		MousePosition = GetMousePosition();    
		cam.target = { player.Position.x , player.Position.y };
		
		BeginDrawing();
		ClearBackground(RAYWHITE);

		// -------------------------------------In Main Menu of the Game----------------------------------//
		if (CurrentState == MENU) {
			DrawTextureEx(Background_Menu, { 0,0 }, 0, 0.286, WHITE);
			MakeTitle("College Simulator");      //Title Function from UI.h

			// ========== Buttons in the Main Menu ==========
			MakeButton({ 400 , 300 , 250 , 50 }, GREEN, GRAY, RED, "START", HOSTELROOM, Pixel , 32);        // TEMPORARY for testing
			MakeButton({ 400 , 400 , 250 , 50 }, YELLOW, GRAY, GOLD, "CREDITS", CREDITS, Pixel, 32);
			MakeButton({ 400 , 500 , 250 , 50 }, GRAY, LIGHTGRAY, DARKGRAY, "SETTING", SETTING, Pixel, 32);
			MakeButton({ 400 , 600 , 250 , 50 }, RED, GRAY, DARKGRAY, "EXIT", EXIT, Pixel, 32);

			Return();
		}

		// ========== State: Choose Player Name ==========
		else if (CurrentState == CHOOSENAME) {
			DrawTextureEx(Background_Menu, { 0,0 }, 0, 0.286, WHITE);
			ChooseName();
			Return();
		}

		// ========== State: Choose Gender ==========
		else if (CurrentState == CHOOSEGENDER) {
			DrawTextureEx(Background_Menu, { 0,0 }, 0, 0.286, WHITE);
			ChooseGender();
			Return();
		}

		// ========== State: Choose Subject[Language] ==========
		else if (CurrentState == CHOOSELANGUAGE) {
			DrawTextureEx(Background_Menu, { 0,0 }, 0, 0.286, WHITE);
			ChooseLanguage();
			Return();
		}

		// ========== State: Hostel Room ==========
		else if (CurrentState == HOSTELROOM) {
			Bar_Make();
			TimeFunction();

			room.MakeRoom({500 , 500} , GRAY , BLACK , RED , "BATHROOM" , BATHROOM);
			room.MakeRoom({ 700 , 300 }, GRAY, BLACK, GREEN, "OUTSIDE", OUTSIDEROOM);
			room.MakeRoom({ 900 , 650 }, BLACK, LIGHTGRAY, MAROON , "PHONE" , PHONE);
		}

		// ========== State: Hostel Bathroom ==========
		else if (CurrentState == BATHROOM) {
			TimeFunction();
			room.Bathroom();
		}

		// ========== State: Outside HostelRoom ==========
		else if (CurrentState == OUTSIDEROOM) {
			BeginMode2D(cam);
			room.OutSideRoom();
			EndMode2D();

			TimeFunction();
			DrawText(TextFormat("X: %.0f Y: %.0f", player.Position.x, player.Position.y), 10, 10, 20, BLACK);
		}

		// -------------------- CREDITS --------------------
		else if (CurrentState == CREDITS) {
			Credits_Function();
			Return();
		}

		// -------------------- EXIT --------------------
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
//=========================================