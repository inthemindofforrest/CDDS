#pragma once
#include "Potion.h"
#include "raylib.h"
#include <string>

using namespace std;


class MYHERO
{
private:
public:
	string Name;
	string Special;
	int Age;
	int HitPoints;
	int MaxHitPoints;
	int Wealth;
	

	Texture2D * Texture = new Texture2D[5];
	Vector2 Position;


	MYHERO(string name, string special, int age, int hitPoints, int maxHitPoints, int wealth);

	MYHERO operator+(const POTION &Potion);
	MYHERO operator+=(const POTION &Potion);

	void Update();
};


