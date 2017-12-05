#ifndef __ACTION_HEADER__
#define __ACTION_HEADER__

#include "Grid.hpp"

class Entity;

//TODO: add objects which trigger incorrect movement

class Action
{
public:
	Action() {}
	~Action() {}

	virtual void Perform(Entity & owner) = 0;
	virtual bool Test(Grid & current_map, Entity & owner) = 0;

protected:

	std::string error_chars;

private:

};
#endif //__ACTION_HEADER__