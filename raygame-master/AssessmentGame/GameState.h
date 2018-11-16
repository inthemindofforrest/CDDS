#pragma once

enum States{MainMenu, Game, EndGame};
class GameState
{
private:
	States State;

	GameState();
	GameState(States CurrentGameState);
	GameState operator=(GameState newState);

public:
	void SetState(States newState);
	States GetState();
	static GameState& GetInstance();
	~GameState();
};