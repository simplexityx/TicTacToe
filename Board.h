#pragma once
#define BOARD_SIZE 9
enum {
	HORIZONTAL = 1,
	RIGHTDIAGONAL = 2,
	VERTICAL = 3,
	LEFTDIAGONAL = 4

};
class Board {
public:
	char board[BOARD_SIZE];
	Board();
	void markBoard(char mark, int placement);
	int checkWin(char mark, int placement);
	int check(int placement, int type, char mark);
	void printBoard();
	int checktie();
};