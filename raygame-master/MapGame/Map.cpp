#include "Map.h"
#include "iostream"
#include <fstream>

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
	DrawObject = 1;
	Preview = false;


	for (int i = 1; i < TotalTextures + 1; i++)
	{
		string FileName = ("mapTile_");

		if (i < 10)
			FileName.append("00");
		else if (i < 100)
			FileName.append("0");

		FileName.append(to_string(i));
		FileName.append(".png");

		AllTiles[i - 1].Texture = LoadTexture(FileName.c_str());
	}


	for (int k = 0; k < Layers; k++)
	{
		for (int j = 0; j < Size; j++)
		{
			for (int i = 0; i < Size; i++)
			{
				if (NewMap[k][j][i] != 0)
				{
					
					MapGrid[k][j][i] = AllTiles[NewMap[k][j][i] - 1];
					MapGrid[k][j][i].Position = { (float)(MapGrid[k][j][i].Texture.width * i),
						(float)(MapGrid[k][j][i].Texture.height * j )};
					MapGrid[k][j][i].Tint = WHITE;
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
					MapGrid[k][i][j].Position.x,
					MapGrid[k][i][j].Position.y, MapGrid[k][i][j].Tint);
			}
		}
	}

	if (IsKeyPressed(KEY_SPACE))
	{
		DrawLayer++;
		if (DrawLayer >= Layers)
		{
			DrawLayer = 1;
		}
	}
	if (IsKeyPressed(KEY_E))
	{
		DrawObject++;
		if (DrawObject >= TotalTextures)
		{
			DrawObject = 0;
		}
	}
	if (IsKeyPressed(KEY_Q))
	{
		DrawObject--;
		if (DrawObject <= 0)
		{
			DrawObject = TotalTextures;
		}
	}
	if (IsKeyPressed(KEY_P))
	{
		Preview = !Preview;
	}

	if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_S))
		SaveMap();
	if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_L))
		LoadMap();

	if (!Preview)
	{
		NewMap[0][0][5] = DrawObject;
		MapGrid[0][0][5] = AllTiles[DrawObject - 1];
		MapGrid[0][0][5].Position = { 5 * 64, 0 };
		DrawRectangleLines(5 * 64, 0, 64, 64, RED);


		if (DrawObject != 0)
		{
			NewMap[0][0][4] = DrawObject - 1;
			MapGrid[0][0][4] = AllTiles[DrawObject - 2];
		}
		else
		{
			NewMap[0][0][4] = TotalTextures;
			MapGrid[0][0][4] = AllTiles[TotalTextures];
		}
		MapGrid[0][0][4].Position = { 4 * 64, 0 };

		if (DrawObject != TotalTextures)
		{
			NewMap[0][0][6] = DrawObject + 1;
			MapGrid[0][0][6] = AllTiles[DrawObject];
		}
		else
		{
			NewMap[0][0][6] = 0;
			MapGrid[0][0][6] = AllTiles[0];
		}
		MapGrid[0][0][6].Position = { 6 * 64, 0 };
		switch (DrawLayer)
		{
		case 1:
			for (int i = 0; i < Size; i++)
			{
				for (int j = 0; j < Size; j++)
				{
					MapGrid[2][j][i].Tint = GRAY;
					MapGrid[2][j][i].Tint.a = 120;
					MapGrid[1][j][i].Tint = WHITE;
				}
			}
			break;
		case 2:
			for (int i = 0; i < Size; i++)
			{
				for (int j = 0; j < Size; j++)
				{
					MapGrid[1][j][i].Tint = GRAY;
					MapGrid[2][j][i].Tint.a = 0;
					MapGrid[2][j][i].Tint = WHITE;
				}
			}
			break;
		default:
			break;
		}
	}
	else
	{
		NewMap[0][0][5] = 187;
		MapGrid[0][0][5] = AllTiles[0];
		MapGrid[0][0][5].Position = { 5 * 64, 0 };

		NewMap[0][0][4] = 187;
		MapGrid[0][0][4] = AllTiles[0];
		MapGrid[0][0][4].Position = { 4 * 64, 0 };

		NewMap[0][0][6] = 187;
		MapGrid[0][0][6] = AllTiles[0];
		MapGrid[0][0][6].Position = { 6 * 64, 0 };

		for (int i = 0; i < Size; i++)
		{
			for (int j = 0; j < Size; j++)
			{
				MapGrid[1][j][i].Tint = WHITE;
				MapGrid[2][j][i].Tint.a = 0;
				MapGrid[2][j][i].Tint = WHITE;
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
		if ( (MousePositionOnGrid.x != 4 && MousePositionOnGrid.y != 0) ||
			(MousePositionOnGrid.x != 5 && MousePositionOnGrid.y != 0 )|| 
			(MousePositionOnGrid.x != 6 && MousePositionOnGrid.y != 0))
		
		{
		NewMap[DrawLayer][(int)(MousePositionOnGrid.y)]
			[(int)(MousePositionOnGrid.x) ] = DrawObject;

		for (int k = 0; k < Layers; k++)
		{
			for (int j = 0; j < Size; j++)
			{
				for (int i = 0; i < Size; i++)
				{
					if (NewMap[k][j][i] != 0)
					{

						MapGrid[k][j][i] = AllTiles[NewMap[k][j][i] - 1];
						MapGrid[k][j][i].Position = { (float)(MapGrid[k][j][i].Texture.width * i),
							(float)(MapGrid[k][j][i].Texture.height * j) };
					}

				}
			}
			}
		}
		//cout << MousePositionOnGrid.x << endl;;
	}
	//if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
	//{
	//	Vector2 MousePositionOnGrid = { GetMouseX() / 64,
	//		GetMouseY() / 64 };
	//	if ((MousePositionOnGrid.x != 4 && MousePositionOnGrid.y != 0) ||
	//		(MousePositionOnGrid.x != 5 && MousePositionOnGrid.y != 0) ||
	//		(MousePositionOnGrid.x != 6 && MousePositionOnGrid.y != 0))

	//	{
	//		NewMap[DrawLayer][(int)(MousePositionOnGrid.y)]
	//			[(int)(MousePositionOnGrid.x)] = DrawObject;

	//		for (int k = 0; k < Layers; k++)
	//		{
	//			for (int j = 0; j < Size; j++)
	//			{
	//				for (int i = 0; i < Size; i++)
	//				{
	//					if (NewMap[k][j][i] != 0)
	//					{
	//						NewMap[k][j][i] = 187;
	//						MapGrid[k][j][i] = AllTiles[187];
	//						MapGrid[k][j][i].Position = { (float)(MapGrid[k][j][i].Texture.width * i),
	//							(float)(MapGrid[k][j][i].Texture.height * j) };
	//					}

	//				}
	//			}
	//		}
	//	}
	//	//cout << MousePositionOnGrid.x << endl;;
	//}
}

void MAP::SaveMap()
{
	fstream File("Save.bin", ios::out | ios::binary);

	if (File.is_open())
	{
		for (int k = 1; k < Layers; k++)
		{
			for (int i = 0; i < Size; i++)
			{
				for (int j = 0; j < Size; j++)
				{
					
						File << to_string(NewMap[k][i][j]);
						if (j != Size - 1)
							File << ",";
				}
				File << "\n";
			}
		}
	}
	else
	{
		cout << "Could not Save file" << endl;
	}
}

void MAP::LoadMap()
{
	fstream file("Save.bin", ios::in | ios::binary);
	string Line;
	string TempInt;

	if (file.is_open())
	{
		for (int k = 1; k < Layers; k++)
		{
			for (int i = 0; i < Size; i++)
			{
				int j = 0;
				Line.clear();
				
				getline(file, Line);
				for (int l = 0; l < Line.length(); l++)
				{
					if (Line[l] != ',')
					{
						TempInt.append(to_string(Line[l]));
					}
					else
					{
						NewMap[k][j][i] = stoi(TempInt);
						j++;
						TempInt.clear();
					}
				}

			}
		}
		file.flush();
		file.close();
	}
	else 
	{
		cout << "Could not Load file" << endl;
	}
}