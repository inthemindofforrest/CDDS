#include "HighScoreTable.h"

bool HighScoreTable::pruneBottomNNScores(int bottomRows)
{
	return false;
}

std::vector<HighScoreEntry> HighScoreTable::topNNScores(int TopRows)
{
	std::vector<HighScoreEntry> Temp;
	HighScoreEntry ScoreTemp;
	for (int i = 0; i < TopRows; i++)
	{
		ScoreTemp.Level = hsVector[i].Level;
		ScoreTemp.Name = hsVector[i].Name;
		ScoreTemp.Score = hsVector[i].Score;
		Temp.push_back(ScoreTemp);
	}
		
	return Temp;
}

HighScoreTable::HighScoreTable()
{

}

HighScoreTable::HighScoreTable(std::string fileName)
{

	std::string CurrentElement;
	std::string Line;
	std::fstream file(fileName, std::ios::in);
	int InputNumber = 0;


	while (getline(file, Line))
	{
		HighScoreEntry Temp;
		for (int i = 0; (i <= Line.length()); i++)
		{
			if (Line[i] == ',' || (i == Line.length()))
			{
				switch (InputNumber)
				{
				case 0:
					Temp.Name = CurrentElement;
					break;
				case 1:
					Temp.Score = stoi(CurrentElement);
					break;
				case 2:
					Temp.Level = stoi(CurrentElement);
					InputNumber = -1;

					hsVector.push_back(Temp);
					break;
				default:
					break;
				}
				CurrentElement.clear();
				InputNumber++;
			}
			else
			{
				if (Line[i] != '\n' || Line[i] != -1)
					CurrentElement += Line[i];
			}
		}
	}
	file.flush();
	file.close();

	BubbleSort();
}

HighScoreTable::~HighScoreTable()
{

}
void HighScoreTable::BubbleSort()
{
	for (int i = 0; i < hsVector.size(); i++)
	{
		for (int j = i; j < hsVector.size(); j++)
		{
			if (hsVector[i].Score > hsVector[j].Score)
			{
				HighScoreEntry Temp = hsVector[i];
				hsVector[i] = hsVector[j];
				hsVector[j] = Temp;
			}
		}
	}
	
}