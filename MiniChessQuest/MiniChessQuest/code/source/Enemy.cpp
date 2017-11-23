#include "../header/Enemy.hpp"

Enemy::Enemy()
{
	position = std::unique_ptr<Vector2>(new Vector2(0, 0));
	symbol = '?';
}

Enemy::~Enemy()
{
}

void Enemy::NextMove()
{
	position->y++; //simple movement
}
