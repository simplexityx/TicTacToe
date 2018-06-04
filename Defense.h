#pragma once
#include "AiState.h"

class DefenseState : public AIState {
	Board *board;
public:
	DefenseState(Board *b){}
	int nextMove(Board *b) override { return 0; }
};