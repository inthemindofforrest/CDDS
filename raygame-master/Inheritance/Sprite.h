#pragma once
#include "raylib.h"
#include "Vector2.h"
#include <iostream>
#include <time.h>

class SPRITE : public Vector2
{
public:
	Texture2D * Texture;//Pointer to the current texture
	float FrameRate;//Rate at which the textures will display
	int FrameCount;//number of sprites that are in the texture array
	int CurrentFrame;
	int Direction;

	bool PlayerControlled;

	float Timer = 0;

	void Draw(time_t deltaTime);
	void Update(time_t deltaTime);

	SPRITE();
	~SPRITE();
	SPRITE(const std::string *fileName, const int cellCount, const float frameRate);

protected:

};