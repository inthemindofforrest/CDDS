#pragma once
#include <iostream>
#include "raylib.h"

template <typename T>
class gameObject
{
public:
	bool Enabled;
	
	T * Object;

	void Update(float deltaTime)
	{
		if (Enabled)
		{
			(*Object).Update(deltaTime);
		}
	}

	gameObject(T* _Object)
	{
		Object = _Object;
		Enabled = true;
	}
	~gameObject()
	{
		delete Object;
	}
};