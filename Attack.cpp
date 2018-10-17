#include "Attack.h"
#include <iostream>

AttackState::AttackState(Board *b) {
	board = b;
	move = 0;
	previous = 0;
}

int checkIfFirstMove(Board *b){
	int count = 0;
	for(int i = 0; i < BOARD_SIZE; i++){
		if(b->board[i] == 'O')
			count++;
	}
	if(count < 1)
		if (b->board[1] == 'X' || b->board[3] == 'X' || b->board[5] == 'X' || b->board[7] == 'X')
			return 4;
	else
		return -1;
}




int possibleToWin(Board *b, int prev) {

	for (int i = 0; i < BOARD_SIZE; i++) {
		switch (i) {
		case 0:
			if (b->board[i] == 'O') {
				if (b->board[i + 1] == 'O' && b->board[i + 2] == 0)
					return i + 2;
				else if (b->board[i + 3] == 'O' && b->board[i + 6] == 0)
					return i + 6;
				else if (b->board[i + 4] == 'O' && b->board[i + 8] == 0)
					return i + 8;
				else if (b->board[i + 2] == 'O' && b->board[i + 1] == 0)
					return i + 1;
				else if (b->board[i + 6] == 'O' && b->board[i + 3] == 0)
					return i + 3;
				else if (b->board[i + 8] == 'O' && b->board[i + 4] == 0)
					return i + 4;
			}
			break;
		case 1:
			if (b->board[i] == 'O') {
				if (b->board[i + 1] == 'O' && b->board[i - 1] == 0)
					return i - 1;
				else if (b->board[i + 3] == 'O' && b->board[i + 6] == 0)
					return i + 6;
				else if (b->board[i - 1] == 'O' && b->board[i + 1] == 0)
					return i + 1;
				else if (b->board[i + 6] == 'O' && b->board[i + 3] == 0)
					return i + 3;
			}
			break;

		case 2:
			if (b->board[i] == 'O') {
				if (b->board[i - 1] == 'O' && b->board[i - 2] == 0)
					return i - 2 ;
				else if (b->board[i + 3] == 'O' && b->board[i + 6] == 0)
					return i + 6;
				else if (b->board[i + 2] == 'O' && b->board[i + 4] == 0)
					return i + 4;
				else if (b->board[i - 2] == 'O' && b->board[i - 1] == 0)
					return i - 1;
				else if (b->board[i + 6] == 'O' && b->board[i + 3] == 0)
					return i + 3;
				else if (b->board[i + 4] == 'O' && b->board[i + 2] == 0)
					return i + 2;
			}
			break;

		case 3:
			if (b->board[i] == 'O') {
				if (b->board[i + 1] == 'O' && b->board[i + 2] == 0)
					return i + 2;
				else if (b->board[i + 3] == 'O' && b->board[i - 3] == 0)
					return i - 3;
				else if (b->board[i + 2] == 'O' && b->board[i + 1] == 0)
					return i + 1;
				else if (b->board[i - 3] == 'O' && b->board[i + 3] == 0)
					return i + 3;
			}
			break;

		case 4:
			if (b->board[i] == 'O') {
				if (b->board[i + 1] == 'O' && b->board[i - 1] == 0)
					return i - 1;
				else if (b->board[i + 3] == 'O' && b->board[i - 3] == 0)
					return i - 3;
				else if (b->board[i + 4] == 'O' && b->board[i - 4] == 0)
					return i - 4;
				else if (b->board[i - 1] == 'O' && b->board[i + 1] == 0)
					return i + 1;
				else if (b->board[i - 3] == 'O' && b->board[i + 3] == 0)
					return i + 3;
				else if (b->board[i - 4] == 'O' && b->board[i + 4] == 0)
					return i + 4;
				else if (b->board[i + 2] == 'O' && b->board[i - 2] == 0)
					return i - 2;
				else if (b->board[i - 2] == 'O' && b->board[i + 2] == 0)
					return i + 2;
			}
			break;

		case 5:
			if (b->board[i] == 'O') {
				if (b->board[i - 1] == 'O' && b->board[i - 2] == 0)
					return i - 2;
				else if (b->board[i + 3] == 'O' && b->board[i - 3] == 0)
					return i - 3;
				else if (b->board[i - 2] == 'O' && b->board[i - 1] == 0)
					return i - 1;
				else if (b->board[i - 3] == 'O' && b->board[i + 3] == 0)
					return i + 3;
				
			}
			break;

		case 6:
			if (b->board[i] == 'O') {
				if (b->board[i + 1] == 'O' && b->board[i + 2] == 0)
					return i + 2;
				else if (b->board[i - 3] == 'O' && b->board[i - 6] == 0)
					return i - 6;
				else if (b->board[i - 2] == 'O' && b->board[i - 4] == 0)
					return i - 4;
				else if (b->board[i + 2] == 'O' && b->board[i + 1] == 0)
					return i + 1;
				else if (b->board[i - 6] == 'O' && b->board[i - 3] == 0)
					return i - 3;
				else if (b->board[i - 4] == 'O' && b->board[i - 2] == 0)
					return i - 2;
			}
			break;

		case 7:
			if (b->board[i] == 'O') {
				if (b->board[i + 1] == 'O' && b->board[i - 1] == 0)
					return i - 1;
				else if (b->board[i - 3] == 'O' && b->board[i - 6] == 0)
					return i - 6;
				else if (b->board[i - 1] == 'O' && b->board[i + 1] == 0)
					return i + 1;
				else if (b->board[i - 6] == 'O' && b->board[i - 3] == 0)
					return i - 3;
			}
			break;

		case 8:

			if (b->board[i] == 'O') {
				if (b->board[i - 1] == 'O' && b->board[i - 2] == 0)
					return i - 2;
				else if (b->board[i - 3] == 'O' && b->board[i - 6] == 0)
					return i - 6;
				else if (b->board[i - 4] == 'O' && b->board[i - 8] == 0)
					return i - 8;
				else if (b->board[i - 2] == 'O' && b->board[i - 1] == 0)
					return i - 1;
				else if (b->board[i - 6] == 'O' && b->board[i - 3] == 0)
					return i - 3;
				else if (b->board[i - 8] == 'O' && b->board[i - 4] == 0)
					return i - 4;
			}
			break;
		}
	}
	return -1;
	
}

//returns -1 if no need to block
int blockPlayerWin(Board *b) {

	for (int i = 0; i < BOARD_SIZE; i++) {
		if (b->board[i] == 'X') {
			switch (i) {

				case 0:
					if (b->board[i + 1] == 'X')
						if(b->board[i + 2] == 0)
							return i + 2;
					if (b->board[i + 2] == 'X') {
						if (b->board[i + 1] == 0)
							return i + 1;
					}
					if (b->board[i + 3] == 'X')
						if (b->board[i + 6] == 0)
							return i + 6;
					if (b->board[i + 6] == 'X')
						if (b->board[i + 3] == 0)
							return i + 3;

					if (b->board[i + 4] == 'X')
						if (b->board[i + 8] == 0)
							return i + 8;
					if (b->board[i + 8] == 'X')
						if (b->board[i + 4] == 0)
							return i + 4;
					break;
				case 1:
					if (b->board[i + 1] == 'X')
						if (b->board[i - 1] == 0)
							return i  - 1;
					if (b->board[i - 1] == 'X') {
						if (b->board[i + 1] == 0)
							return i + 1;
					}
					if (b->board[i + 3] == 'X')
						if (b->board[i + 6] == 0)
							return i + 6;

					break;

				case 2:
					if (b->board[i - 1] == 'X')
						if (b->board[i - 2] == 0)
							return i - 2;
					if (b->board[i + 3] == 'X')
						if (b->board[i + 6] == 0)
							return i + 6;
					if (b->board[i + 6] == 'X')
						if (b->board[i + 3] == 0)
							return i + 3;
					if (b->board[i + 2] == 'X')
						if (b->board[i + 4] == 0)
							return i + 4;
					if (b->board[i + 4] == 'X')
						if (b->board[i + 2] == 0)
							return i + 2;
					break;

				case 3:
					if (b->board[i + 1] == 'X')
						if (b->board[i + 2] == 0)
							return i + 2;
					if (b->board[i + 2] == 'X')
						if (b->board[i + 1] == 0)
							return i + 1;
					if (b->board[i + 3] == 'X') {
						if (b->board[i - 3] == 0)
							return i - 3;
					}
					if (b->board[i - 3] == 'X')
						if (b->board[i + 3] == 0)
							return i + 3;
					break;

				case 4:
					if (b->board[i + 1] == 'X')
						if (b->board[i - 1] == 0)
						return i - 1;
					if (b->board[i - 1] == 'X')
						if (b->board[i + 1] == 0)
						return i + 1;
					if (b->board[i + 3] == 'X') {
						if (b->board[i - 3] == 0)
						return i - 3;
					}
					if (b->board[i - 3] == 'X')
						if (b->board[i + 3] == 0)
						return i + 3;
					if (b->board[i + 4] == 'X')
						if (b->board[i - 4] == 0)
						return i - 4;
					if (b->board[i - 4] == 'X')
						if (b->board[i + 4] == 0)
						return i + 4;
					if (b->board[i + 2] == 'X')
						if (b->board[i - 2] == 0)
						return i - 2;
					if (b->board[i - 2] == 'X')
						if (b->board[i + 2] == 0)
						return i + 2;
					break;

				case 5:
					if (b->board[i - 1] == 'X')
						if (b->board[i - 2] == 0)
						return i - 2;
					if (b->board[i - 2] == 'X')
						if (b->board[i - 1] == 0)
							return i - 1;
					if (b->board[i + 3] == 'X') {
						if (b->board[i - 3] == 0)
						return i - 3;
					}
					if (b->board[i - 3] == 'X')
						if (b->board[i + 3] == 0)
						return i + 3;

					break;

				case 6:
					

					if (b->board[i + 1] == 'X')
						if (b->board[i + 2] == 0)
							return i + 2;
					if (b->board[i + 2] == 'X') {
						if (b->board[i + 1] == 0)
							return i + 1;
					}
						
					if (b->board[i - 3] == 'X')
						if (b->board[i - 6] == 0)
						return i - 6;
					if (b->board[i - 6] == 'X')
						if (b->board[i - 3] == 0)
							return i - 3;

					if (b->board[i - 2] == 'X')
						if (b->board[i - 4 ] == 0)
						return i - 4;

					if (b->board[i - 4] == 'X')
						if (b->board[i - 2] == 0)
							return i - 2;
					break;


				case 7:
					if (b->board[i + 1] == 'X')
						if (b->board[i - 1] == 0)
						return i - 1;
					if (b->board[i - 1] == 'X') {
						if (b->board[i + 1] == 0)
						return i + 1;
					}
					if (b->board[i - 3] == 'X')
						if (b->board[i - 6] == 0)
						return i - 6;
					if (b->board[i - 6] == 'X')
						if (b->board[i - 3] == 0)
							return i - 3;
					break;

				case 8:
					if (b->board[i - 1] == 'X')
						if (b->board[i - 2] == 0)
						return i - 2;
					if (b->board[i - 2] == 'X')
						if (b->board[i - 1] == 0)
							return i - 1;
					if (b->board[i - 3] == 'X')
						if (b->board[i - 6] == 0)
						return i - 6;
					if (b->board[i - 6] == 'X')
						if (b->board[i - 3] == 0)
							return i - 3;
					if (b->board[i - 4] == 'X')
						if (b->board[i - 8] == 0)
						return i - 8;
					if (b->board[i - 8] == 'X')
						if (b->board[i - 4] == 0)
							return i - 4
							;
					
					break;

			}
			
		}


	}
	return -1;
}


int checkCorners(Board *b) {

	if (b->board[0] == 'X' || b->board[2] == 'X' || b->board[6] == 'X' || b->board[8] == 'X') {
		if(b->board[4] == 0)
			return 4;
	}

	if (b->board[0] == 0) {
		return 0;
	}
	else if (b->board[2] == 0) {
		return 2;
	}
	else if (b->board[6] == 0) {
		return 6;
	}
	else if (b->board[8] == 0) {
		return 8;
	}
	return -1;
}



int marknextToPrev(Board *b, int prev) {

	if (prev == 0 || prev == 8 || prev == 4) {
		if (b->board[prev + 4] == 0) {
			return prev + 4;
		}
		if (b->board[prev - 4] == 0) {
			return prev - 4;
		}
	}
	else if (prev == 2 || prev == 6) {
		if (b->board[prev + 2] == 0) {
			return prev + 2;
		}
		if (b->board[prev - 2] == 0) {
			return prev - 2;
		}
	}

	if (b->board[prev + 1] == 0 && prev + 1 <= 8) {
		return prev + 4;
	}
	if (b->board[prev - 1] == 0 && prev - 1 >= 0) {
		return prev - 1;
	}
	if (b->board[prev - 3] == 0 && prev - 3 >= 0) {
		return prev - 3;
	}
	if (b->board[prev + 3] == 0 && prev + 3 >= 0) {
		return prev + 3;
	}
	return -1;
}


int findRandom(Board *b) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (b->board[i] == 0)
			return i;
	}
	return -1;
}


int AttackState::nextMove(Board *b) {
	board = b;
	int next = 0;
		
	next = checkIfFirstMove(b);
	if (next != -1)
		goto endTurn;

	next = possibleToWin(b, previous);
	if (next != -1)
		goto endTurn;

	next = blockPlayerWin(b);
	if (next != -1)
		goto endTurn;

	next = checkCorners(b);
	if (next != -1)
		goto endTurn;

	if (board->board[4] == 0) {
		next = 4;
		goto endTurn;
	}
	
	next = marknextToPrev(b, previous);
	if (next != -1)
		goto endTurn;

	next = findRandom(b);
	if (next != -1)
		goto endTurn;

	endTurn:
		std::cout << next << std::endl;
		b->markBoard('O', next);
		previous = next;
		if (b->checkWin('O', next) == 1) {
			b->printBoard();
			
			std::cout << "AI Wins\n";
			return 42;
		}
		b->printBoard();
	
	return 0;

}




