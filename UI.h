#pragma once

// UI.h
// ---------
// Used for making game UI

#include "Common.h"
#include "Assets.h"
#include "Player.h"
#include "MainGame.h"
#include <raylib.h>
#include <raymath.h>

// ---------- TITLE ----------
struct Title {
	float Alpha;    // Title's transparency
 	float DirX;     // X - cord
	float DirY;     // Y - cord
};
extern Title title;


// ---------- BLACKSCREEN ----------
// Used when changing states
struct BlackScreen {
	float Alpha;
	int Dir;
};
extern BlackScreen blackscreen;


// ---------- BUTTON ----------
void MakeButton(Rectangle Btn,  // Rectangle Box of the button
	Color Normal,         // Normal color
	Color Touch,          // Color when in contact
	Color Click,          // Color when button is clicked
	const char* BtnName,  // Name
	State NextState,      // Which state will button take 
	Font FontFamily,      // Font used
	int Size              // Size of text in the button
);  


// This makes the title of the game
void MakeTitle(const char* Title);


// Blackscreen update and start functions
void StartBlackScreen(State Next);
void BlackScreen_Update(Color color);


// ========== Function Declaration ==========
void Credits_Function();
void Return();