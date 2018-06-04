#pragma once
#include "Attack.h"
#include "Defense.h"

class AI {
private:
	AIState *currentState;
	AttackState *attackState;
	DefenseState *defenseState;
	Board *board;
public:

	AI(Board *b);

	void setState(AIState *state);
	int nextMove(Board *b);
	AttackState *getAttackState();
	DefenseState *getDefenseState();

};