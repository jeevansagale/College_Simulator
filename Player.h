#pragma once
class Player
{
public:
	std::string Gender;
	std::string Name;
	
	float Attendance;
	float Stress;
	float Reputation;
	float ToiletMeter;

	Player();
	void Attendance_Function();
	void Stress_Function();
	void Reputation_Function();
	void Toilet_Function();
};

