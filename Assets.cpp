#include "Assets.h"

// Texture filtering modes:
// - TEXTURE_FILTER_POINT     → Sharp, pixelated look (pixel fonts / pixel art)
// - TEXTURE_FILTER_BILINEAR  → Smooth interpolation (normal fonts)


// ==================== FONTS ====================
Font Pixel;
Font Thick_Pixel;
Font Thick;
Font Icons;

// ==================== TEXTURES ====================
Texture2D Background_Menu;


// Loading Fonts
void LoadFonts() {
	Pixel = LoadFontEx("Assets/Font/editundo.ttf", 32, 0, 0);
	SetTextureFilter(Pixel.texture, TEXTURE_FILTER_POINT);

	Thick_Pixel = LoadFontEx("Assets/Font/ka1.ttf", 64, 0, 0);
	SetTextureFilter(Thick_Pixel.texture, TEXTURE_FILTER_POINT);

	Thick = LoadFontEx("Assets/Font/GravitasOne-Regular.ttf" , 32 , 0 , 0);
	SetTextureFilter(Thick.texture, TEXTURE_FILTER_BILINEAR);

	Icons = LoadFontEx("Assets/Font/ionicons.ttf" , 32 , 0 , 0);
	SetTextureFilter(Icons.texture, TEXTURE_FILTER_BILINEAR);
}

// Unloading Fonts
void UnLoadFonts() {
	UnloadFont(Pixel);
	UnloadFont(Thick_Pixel);
	UnloadFont(Thick);
	UnloadFont(Icons);
}

// Loading Textures
void LoadTextures() {
	Background_Menu = LoadTexture("Assets/Background/v960-ning-03.png");
}

// Unloading Textures
void UnLoadTexures() {
	UnloadTexture(Background_Menu);
}