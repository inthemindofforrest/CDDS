#include "Gamestate.h"

void GameState::operator=(GameState const &)
{

}

GameState::GameState()
{
	state = MainMenu;
}

int GameState::getState()
{
	return state;
}

int GameState::setState(int newState)
{
	state = newState;
	return newState;
}

GameState & GameState::GetInstance()
{
	static GameState Instance;
	return Instance;
}

GameState::~GameState()
{
}
