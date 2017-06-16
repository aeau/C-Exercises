#ifndef __WALL_HEADER__
#define __WALL_HEADER__

#include "Object.hpp"

class Wall : Object
{
public:
	Wall();
	Wall(float _x, float _y);
	~Wall();

	virtual bool Update() override;

private:

};

#endif //__WALL_HEADER__