#include "../headers/Player.hpp"

Player::Player()
{
	my_symbol = '@';
	position = Vector2();
	Elements::getInstance().RegisterObject(this);
}

Player::Player(int x, int y)
{
	position = Vector2(x, y);
	my_symbol = '@';
	Elements::getInstance().RegisterObject(this);
}

Player::~Player()
{
}

bool Player::Update()
{
	std::string action = "";
	std::cout << "WHAT WILL BE YOUR NEXT MOVE" << std::endl;
	std::getline(std::cin, action);
	//std::cout << "your action is to " << action << std::endl;

	if (action == "exit")
	{
		return true;
	}
	else if (action == "e")
	{
		position.x++;
	}
	else if (action == "s")
	{
		position.y++;
	}
	else if (action == "w")
	{
		position.x--;
	}
	else if (action == "n")
	{
		position.y--;
	}

	return false;
}