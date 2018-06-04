#include "Game.h"
#include <iostream>
Game::Game() {
	board = new Board();
	ai = new AI(board);
}

int Game::checkTie() {
	return board->checktie();
}

int Game::playerTurn() {
	std::cout << "\n\n Player Turn \n\n";
	int cmd;
	int won = 0;
	int turn = 0;
	while (turn == 0) {
		std::cin >> cmd;
		if (cmd < 0 || cmd > 8) {
			std::cout << "only 0 -> 8 are valid inputs!\n";
		}
		else if (board->board[cmd] == 0) {
			board->markBoard('X', cmd);
			won = board->checkWin('X', cmd);
			if (won == 1) {
				board->printBoard();
				std::cout << "\n" << "PLAYER WON!" << std::endl;
				return 42;
			}
			board->printBoard();

			turn = 1;
		}
		else {
			std::cout << "space already taken!\n";
		}

	}
	return cmd;
}

int Game::opponentTurn() {
	std::cout << "\n\nAI TURN \n\n";
	return ai->nextMove(board);

}