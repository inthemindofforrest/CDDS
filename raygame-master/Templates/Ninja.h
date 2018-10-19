#pragma once
#include <iostream>
#include "raylib.h"

class NINJA
{
public:
	bool PlayerControlled;
	Vector2 Position;
	Texture2D Texture;
	float Speed;

	void Update(float deltaTime);
	void Render();
	NINJA(const std::string & fileName, Vector2 position, float speed, bool playerControlled);

};