#include "Assets.h"


Font Pixel;
Font Thick_Pixel;
Font Thick;
Font Icons;

Texture2D Background_Menu;


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

void UnLoadFonts() {
	UnloadFont(Pixel);
	UnloadFont(Thick_Pixel);
	UnloadFont(Thick);
	UnloadFont(Icons);
}

void LoadTextures() {
	Background_Menu = LoadTexture("Assets/Background/v960-ning-03.png");
}

void UnLoadTexures() {
	UnloadTexture(Background_Menu);
}