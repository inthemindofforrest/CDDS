#pragma once
#include "raylib.h"
#include <string>

using std::string;

class POTION
{
private:
public:
	string Name;
	int HPModifier;
	int Quality;
	int UseByDate;

	POTION(string name, int hpModifier, int quality, int useByDates);

};