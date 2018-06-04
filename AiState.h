#pragma once
#include "Board.h"

class AIState {

public:
	virtual int nextMove(Board *b) { return 0; }

};