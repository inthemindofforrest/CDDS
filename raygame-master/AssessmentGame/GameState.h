#pragma once

enum States{MainMenu, Game, EndGame};
class GameState
{
private:
	States State;

	GameState();
	GameState(States CurrentGameState);


};