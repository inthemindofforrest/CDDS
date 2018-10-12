#include "Map.h"


TILE::TILE()
{
	Position = { 0,0 };
	TileType = 0;
}

TILE& TILE::operator=(const TILE &map) 
{
	
	(*this).Texture = map.Texture;
	return (*this);
}

//MAP-------------------------------------------------------------------

MAP::MAP()
{
	DrawLayer = 1;
	DrawObject = 188;

	for (int i = 1; i < TotalTextures + 1; i++)
	{
		string FileName = ("mapTile_");

		if (i < 10)
			FileName.append("00");
		else if (i < 100)
			FileName.append("0");

		FileName.append(to_string(i));
		FileName.append(".png");

		AllTiles[i].Texture = LoadTexture(FileName.c_str());
	}


	for (int k = 0; k < Layers; k++)
	{
		for (int j = 0; j < Size; j++)
		{
			for (int i = 0; i < Size; i++)
			{
				if (NewMap[k][j][i] != 0)
				{
					
					MapGrid[k][i][j] = AllTiles[NewMap[k][j][i]];
				}

			}
		}
	}
}


void MAP::UpdateMapTextures()
{
	for (int k = 0; k < Layers; k++)
	{
		for (int i = 0; i < Size; i++)
		{
			for (int j = 0; j < Size; j++)
			{

				DrawTexture(MapGrid[k][i][j].Texture,
					MapGrid[k][i][j].Texture.width * i,
					MapGrid[k][i][j].Texture.height * j, WHITE);
			}
		}
	}
}

void MAP::DrawOnMap()
{
	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
	{
		Vector2 MousePositionOnGrid = {GetMouseX() / 64, 
			GetMouseY() / 64 };
		NewMap[DrawLayer][(int)(MousePositionOnGrid.x)]
			[(int)(MousePositionOnGrid.y)] = DrawObject;
	}
}