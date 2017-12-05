#include "../header/Player.hpp"

Player::Player()
{
	position = std::unique_ptr<Vector2>(new Vector2(0, 0));
	symbol = '@';

	//Set all the possible movements
	possible_actions.push_back(actionSequence{ 
		std::make_shared<Move>(Move(Vector2(0,-2))), 
		std::make_shared<Move>(Move(Vector2(-1,0))) 
	});

	possible_actions.push_back(actionSequence{
		std::make_shared<Move>(Move(Vector2(0,-2))),
		std::make_shared<Move>(Move(Vector2(1,0)))
	});

	possible_actions.push_back(actionSequence{
		std::make_shared<Move>(Move(Vector2(2,0))),
		std::make_shared<Move>(Move(Vector2(0,-1)))
	});

	possible_actions.push_back(actionSequence{
		std::make_shared<Move>(Move(Vector2(2,0))),
		std::make_shared<Move>(Move(Vector2(0,1)))
	});

	possible_actions.push_back(actionSequence{
		std::make_shared<Move>(Move(Vector2(0,2))),
		std::make_shared<Move>(Move(Vector2(1,0)))
	});

	possible_actions.push_back(actionSequence{
		std::make_shared<Move>(Move(Vector2(0,2))),
		std::make_shared<Move>(Move(Vector2(-1,0)))
	});

	possible_actions.push_back(actionSequence{
		std::make_shared<Move>(Move(Vector2(-2,0))),
		std::make_shared<Move>(Move(Vector2(0,1)))
	});

	possible_actions.push_back(actionSequence{
		std::make_shared<Move>(Move(Vector2(-2,0))),
		std::make_shared<Move>(Move(Vector2(0,-1)))
	});

}

Player::~Player()
{
}

void Player::NextMove()
{
}
