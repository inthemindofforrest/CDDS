#pragma once
#include "raylib.h"
#include <string>

using namespace std;


class TILE
{
private:
public:
	int TileType;
	Vector2 Position;
	Texture2D Texture;

	Color Tint;

	TILE();
	TILE& operator=(const TILE &tile);
};

class MAP
{
private:
	const static int Size = 10;
	const static int Layers = 3;
	const static int TotalTextures = 188;
	int DrawLayer;
	int DrawObject;
	bool Preview;

public:
	TILE MapGrid[Layers][Size][Size];
	int NewMap[Layers][Size][Size] =
	{
	{
	{ 188,188,188,188,188,188,188,188,188,188 },
	{ 188,188,188,188,188,188,188,188,188,188 },
	{ 188,188,188,188,188,188,188,188,188,188 },
	{ 188,188,188,188,188,188,188,188,188,188 },
	{ 188,188,188,188,188,188,188,188,188,188 },
	{ 188,188,188,188,188,188,188,188,188,188 },
	{ 188,188,188,188,188,188,188,188,188,188 },
	{ 188,188,188,188,188,188,188,188,188,188 },
	{ 188,188,188,188,188,188,188,188,188,188 },
	{ 188,188,188,188,188,188,188,188,188,188 }
		},
	{
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 }
	},
	{
		{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 }
	}
	};
	TILE AllTiles[TotalTextures];

	MAP();
	
	void UpdateMapTextures();
	void DrawOnMap();

	void SaveMap();
	void LoadMap();
};

