
#include "AI.h"


AI::AI(Board *b) {
	board = b;
	attackState = new AttackState(board);
	defenseState = new DefenseState(board);
	currentState = attackState;
}

int AI::nextMove(Board *b) {
	return currentState->nextMove(b);
}

void AI::setState(AIState *state) {
	currentState = state;
}

AttackState *AI::getAttackState() {
	return attackState;
}

DefenseState *AI::getDefenseState() {
	return defenseState;
}