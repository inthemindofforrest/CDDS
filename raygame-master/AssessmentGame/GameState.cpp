#include "GameState.h"

GameState::GameState(){}
GameState::GameState(States CurrentGameState) { State = CurrentGameState; }
GameState GameState::operator=(GameState newState) {}

void GameState::SetState(States newState) 
{ 
	State = newState; 
}
States GameState::GetState()
{
	return State;
}
GameState& GameState::GetInstance()
{
	static GameState Instance;
	return Instance;
}
GameState::~GameState(){}