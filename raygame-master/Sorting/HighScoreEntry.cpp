#include "HighScoreEntry.h"

HighScoreEntry::HighScoreEntry()
{

}

HighScoreEntry::HighScoreEntry(std::string name, int score, int level)
{
	Name = name;
	Score = score;
	Level = level;
}

HighScoreEntry::~HighScoreEntry()
{

}
