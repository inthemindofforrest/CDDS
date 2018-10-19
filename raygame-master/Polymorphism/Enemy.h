#pragma once
//Enemy.h
#pragma once
#include "raylib.h"
#include <iostream>
class ENEMY
{
public:
	Vector2 position = { 100,100 };
	Vector2 destination = { 0,0 };
	float speed = 0;
	Texture2D mySprite;

	virtual void moveTo() = 0;
	virtual void Update() = 0;

	ENEMY(const std::string & fileName);
	ENEMY();
	~ENEMY();
};