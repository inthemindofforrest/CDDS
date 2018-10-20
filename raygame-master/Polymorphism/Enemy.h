#pragma once
#include "raylib.h"
#include <iostream>
#include <vector>
#include <string>
#include "Player.h"


class ENEMY
{
public:
	Vector2 position;
	Vector2 destination;
	float speed;
	bool IsAlive = false;

	Texture2D mySprite;
	PLAYER * player;

	virtual void moveTo();
	virtual void Update();
	void Draw();

	ENEMY(const std::string & fileName);
	ENEMY();
	~ENEMY();
};