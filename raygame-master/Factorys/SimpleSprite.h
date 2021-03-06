//SimpleSprite.h
#pragma once
#include <iostream>
#include "raylib.h"
class SimpleSprite
{
public:
	std::string sprType;
	Vector2 pos;
	float rot;
	Rectangle r1, r2;//r1 = size of texture , r2 = calculated destination size
	Texture2D texture;

	void translate(Vector2 delta); // move the sprites position by delta.
	void draw(); //draw the sprite on screen
	SimpleSprite();
	SimpleSprite(const std::string & filename, const std::string _sprType = "", float scale = 1);
	~SimpleSprite();

	void operator=(SimpleSprite const&copy);
	bool operator==(SimpleSprite &Other);

	void Resize(float newSize);

	SimpleSprite * Clone();
	SimpleSprite * CloneRandom();
};