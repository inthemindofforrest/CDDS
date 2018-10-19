//Player.h
#pragma once
#include "raylib.h"
#include <iostream>
#include <string>
class PLAYER{public:Vector2 position = { 100,100 };Vector2 destination = { 0,0 };float speed = 0;Texture2D mySprite;virtual void moveTo() = 0;virtual void Update() = 0;PLAYER();PLAYER(const std::string & fileName);~PLAYER();void Draw();bool IsMouseClicked();};