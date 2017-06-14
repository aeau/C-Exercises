#ifndef __PLAYER_HEADER__
#define __PLAYER_HEADER__

#include <sstream>
#include "Object.hpp"

class Player : Object
{
public:
	
	Player();
	Player(int x, int y);
	~Player();

	virtual bool Update() override;

private:

};

#endif //__PLAYER_HEADER__