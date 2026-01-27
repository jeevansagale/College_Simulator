#include "MainGame.h"

Eyes eyes{
	-400 ,
	1200 ,
	0 , 
	1 , 
	-1 , 
	500
};

void EyesOpen() {
	float dt = GetFrameTime();
	eyes.Size += dt * 600;
	eyes.UpperEye += dt * 200 * eyes.dirUP + eyes.Size;
	eyes.LowerEye += dt * 200 * eyes.dirDOWN + eyes.Size;
	eyes.Alpha += dt * eyes.dirUP;

	if (eyes.UpperEye >= 450) { eyes.dirUP = -1; }
	if (eyes.LowerEye <= 450) { eyes.dirDOWN = 1; }

	eyes.UpperEye = Clamp(eyes.UpperEye, -450, 450);
	eyes.LowerEye = Clamp(eyes.LowerEye, 450, 1350);
	eyes.Alpha = Clamp(eyes.Alpha, 0.0f, 1.0f);

	DrawRectangle(0, eyes.UpperEye, 1100, eyes.UpperEye, Fade(BLACK, eyes.Alpha));
	DrawRectangle(0, eyes.LowerEye, 1100, eyes.LowerEye, Fade(BLACK, eyes.Alpha));
}

void HostelRoom() {

}