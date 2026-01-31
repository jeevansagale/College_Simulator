#pragma once

#include <raylib.h>

// Assets.h
// ----------
// Declares all global fonts, textures, and asset-loading functions
// Used across the game to manage shared visual resources

// ==================== FONTS ====================

// Pixel-style font used for UI and small text
extern Font Pixel;      

// Thicker pixel font for titles and emphasis
extern Font Thick_Pixel;

// Standard thick font
extern Font Thick;

// Icon font (symbols, UI icons)
extern Font Icons;



// ==================== TEXTURES ====================

// Background for Menu
extern Texture2D Background_Menu;


//---------- Laoding Textures, Music, Sound ----------
void LoadFonts();
void LoadTextures();

//---------- UnLaoding Textures, Music, Sound ----------
void UnLoadFonts();
void UnLoadTexures();

