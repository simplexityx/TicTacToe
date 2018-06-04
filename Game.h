#pragma once
#include "Board.h"
#include "AI.h"
class Game {

private:
	Board *board;
	AI *ai;
public:
	Game();

	int checkTie();
	int playerTurn();
	int opponentTurn();


};