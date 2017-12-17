#include "../header/Enemy.hpp"

Enemy::Enemy()
{
	position = std::unique_ptr<Vector2>(new Vector2(0, 0));
	symbol = '?';

	//Set all the possible movements
	possible_actions.push_back(actionSequence{ std::make_shared<Move>(Move(Vector2(0,1))) });
}

Enemy::~Enemy()
{
}

void Enemy::NextMove()
{
	//At the moment there is not any 

	/*possible_actions[0]*/
	position->y++; //simple movement
}
