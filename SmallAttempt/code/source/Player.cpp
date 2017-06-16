#include "../headers/Player.hpp"

Player::Player() : Object()
{
	my_symbol = '@';
	position = Vector2();
	//Elements::getInstance().RegisterObject(this);
}

Player::Player(int x, int y) : Object()
{
	position = Vector2(x, y);
	my_symbol = '@';
	//Elements::getInstance().RegisterObject(this);
}

Player::~Player()
{
}

bool Player::Update()
{
	std::string action = "";
	std::cout << "WHAT WILL BE YOUR NEXT MOVE" << std::endl;
	float j = 0;

	/*while (j < 1000000000)
	{
		j += 0.1;
	}
	
	std::cout << "SIIIIIIIIIIIIIIIIIIIIIIIIII" << std::endl;*/
	std::getline(std::cin, action);
	//std::cout << "your action is to " << action << std::endl;

	if (action == "exit")
	{
		Elements::getInstance().thread_conditional.notify_one();
		return true;
	}
	else if (action == "quit")
	{
		//Elements::getInstance().UnregisterObject(element_index);
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

	Elements::getInstance().thread_conditional.notify_one();
	return false;
}