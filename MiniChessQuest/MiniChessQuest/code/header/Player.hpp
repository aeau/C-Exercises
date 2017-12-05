#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Entity.hpp"
#include "Move.hpp"

class Player : public Entity
{
public:
	Player();
	~Player();

public:

	virtual void NextMove();

};

#endif //PLAYER_HEADER