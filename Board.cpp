#include "Board.h"
#include <iostream>


Board::Board() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		board[i] = 0;
	}
}

void Board::markBoard(char mark, int placement) {
	board[placement] = mark;
	return;
}

void Board::printBoard() {
	std::cout << "\n";
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (i % 3 == 0)
			std::cout << "\n";
		std::cout << "|" << board[i] << "\t";
	}
	std::cout << "\n";
}

int Board::check(int placement, int type,  char mark) {
	int win = 0;
	int tt = placement;
	while ((placement % 3) != 0) {
		if (board[placement - type] == mark) {
			placement -= type;
			win++;
		}
		else {
			break;
		}

	}
	placement = tt;
	while ((placement % 3) != 2) {
		if (board[placement + type] == mark) {
			placement += type;
			win++;
		}
		else {
			break;
		}
	}
	if (win >= 2)
		return 1;

	return 0;

}

int Board::checktie() {

	for (int i = 0; i < BOARD_SIZE; i++) {
		if (board[i] == 0) {
			return 0;
		}
	}
	return 1;
}


int Board::checkWin(char mark, int placement) {
	int won = 0;
	int winCon = 0;
	//left right check
	if (check(placement, HORIZONTAL, mark) == 1) {
		return 1;
	}
	//up down check
	if (placement == 8 || placement == 2) {
		if (board[8] == mark && board[5] == mark && board[2] == mark)
			return 1;
	}
	if (placement == 6 || placement == 0) {
		if (board[6] == mark && board[3] == mark && board[0] == mark)
			return 1;
	}
	if (check(placement, VERTICAL, mark) == 1) {
		
		return 1;
	}


	//skr� h�yre til venstre
	if (placement == 0 || placement == 4 || placement == 8) {
		if (check(placement, LEFTDIAGONAL, mark) == 1) {
			return 1;
		}
	}
	//skr� venstre til h�yre
	if (placement == 6 || placement == 4 || placement == 2) {
		
		if (board[6] == mark && board[2] == mark && board[4] == mark) {
			return 1;
		}
		
	}
	return 0;
}


