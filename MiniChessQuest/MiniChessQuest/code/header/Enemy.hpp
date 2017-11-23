#ifndef ENEMY_HEADER
#define ENEMY_HEADER

#include "Entity.hpp"

class Enemy : public Entity
{
public:
	Enemy();
	~Enemy();

public:

	virtual void NextMove();

private:

};

#endif //ENEMY_HEADER