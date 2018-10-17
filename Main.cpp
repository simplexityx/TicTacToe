#include "Game.h"
#include <iostream>
Game *g;


int main() {
	g = new Game();
	int victory = 0;
	while (1) {
		if (g->playerTurn() == 42) 
			break;
		if (g->opponentTurn() == 42)
			break;
		if (g->checkTie() == 1) {
			std::cout << "draw \n";
			break;
		}

	}
	return 0;
}