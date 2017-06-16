#include "../headers/Wall.hpp"

Wall::Wall() : Object()
{

}

Wall::Wall(float _x, float _y) : Object()
{
	position = Vector2(_x, _y);
	my_symbol = '#';
}

Wall::~Wall()
{

}

bool Wall::Update()
{
	return false;
}