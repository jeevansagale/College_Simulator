#pragma once

#define MAX_CHARACTER 20

#include <string>
#include <raylib.h>
#include "UI.h"
#include "Assets.h"
#include "Common.h"

extern bool Clicked2;
extern bool Clicked1[5];
extern bool Clicked[5];

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
	std::string Subject;
	
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

void ChooseGenderBox(Rectangle Box, Color BoxColor, Color BoxHover, Color BoxClick, int Index, const char* Gender);
void ChooseGender();

void ChooseLanguageBox(Rectangle Box , Color BoxColor , Color BoxHover , Color BoxClick , int Index, const char* Language);
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


