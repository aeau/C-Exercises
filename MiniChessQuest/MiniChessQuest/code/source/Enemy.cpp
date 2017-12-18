#include "../header/Enemy.hpp"

Enemy::Enemy()
{
	position = std::unique_ptr<Vector2>(new Vector2(0, 0));
	symbol = '?';

	//Set all the possible movements
	//possible_actions.push_back(actionSequence{ std::make_shared<Move>(Move(Vector2(0,1))) });
	possible_actions = std::make_shared<ActionPattern>(ActionPattern());
	possible_actions->AddAction(std::make_shared<Move>(Move(Vector2(0, 1))));
}

Enemy::~Enemy()
{
}

void Enemy::NextMove()
{
	//At the moment there is not any strategy, just check randomly for a sequence and do it
	possible_actions->PerformSequence(0, *this);

	/*possible_actions[0]*/
	//position->y++; //simple movement
}
