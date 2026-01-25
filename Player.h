#pragma once

#define MAX_CHARACTER 20

#include <string>
#include <raylib.h>
#include "UI.h"
#include "Assets.h"
#include "Common.h"

extern bool clicked;
extern bool clicked1;
extern bool clicked2;

class Player
{
public:
	float Max_Attendance;
	float Max_Stress;
	float Max_Reputation;
	float Max_ToiletMeter;
	float Max_LoveMeter;
	float Max_SleepMeter;

	std::string Gender;
	std::string Name;
	
	float Attendance;
	float Stress;
	float Reputation;
	float ToiletMeter;
	float LoveMeter;        
	float SleepMeter;

	Player();

	void Attendance_Function();
	void Stress_Function();
	void Reputation_Function();
	void Toilet_Function();
	void Love_Function();
	void Sleep_Function();
};
extern Player player;

void ChooseName();
void ChooseGender(Color BoxColor1, Color BoxColor2, Color BoxColorClick1, Color BoxColorClick2, Color Click1, Color Click2);
void ChooseLanguage();
void MakeBar(Vector2 Position, int Index , float Percantage , Color Base , Color BarColor , Color Border, const char* BarName);
void Bar_Make();

struct BarMake {
	float BarH;
	float BarW;
	float BarNewW;
	Rectangle Bar;
};
extern BarMake barmake[50];


