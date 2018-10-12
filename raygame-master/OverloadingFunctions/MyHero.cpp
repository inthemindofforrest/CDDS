#include "MyHero.h"

MYHERO::MYHERO(string name, string special, int age, int hitPoints, int maxHitPoints, int wealth)
{
	Name = name;
	Special = special;
	Age = age;
	HitPoints = hitPoints;
	MaxHitPoints = maxHitPoints;
	Wealth = wealth;
	Position = { 100,100 };

	for (int i = 5; i > 0 - 1; i--)
	{
		string FileName("ouch");
		FileName.append(to_string(i));
		FileName.append(".png");
		Texture[i] = LoadTexture(FileName.c_str());
	}
}

MYHERO MYHERO::operator+(const POTION &Potion)
{
	MYHERO NewHero = (*this);

	NewHero.HitPoints += Potion.HPModifier;

	if (NewHero.HitPoints > NewHero.MaxHitPoints)
		NewHero.HitPoints = NewHero.MaxHitPoints;

	return NewHero;
}

MYHERO MYHERO::operator+=(const POTION &Potion)
{
	(*this) = (*this) + Potion;

	if ((*this).HitPoints > (*this).MaxHitPoints)
		(*this).HitPoints = (*this).MaxHitPoints;

	return (*this);
}

void MYHERO::Update()
{
	DrawTexture(Texture[HitPoints], (int)Position.x, (int)Position.y, WHITE);
}