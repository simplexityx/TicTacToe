#pragma once
#include "AiState.h"
class AttackState : public AIState {
	Board *board;
public:
	int move;
	int previous;
	AttackState(Board *b);
	int nextMove(Board *b) override;
};