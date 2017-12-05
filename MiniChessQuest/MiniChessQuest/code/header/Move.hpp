#ifndef __MOVE_HEADER__
#define __MOVE_HEADER__

#include "Action.hpp"
#include "Vector2.hpp"
class Move : public Action
{
public:
	Move(const float & x, const float & y);
	Move(const Vector2 & xy);
	~Move();

	virtual void Perform(Entity & owner);
	virtual bool Test(Grid & current_map, Entity & owner);

private:

	Vector2 additive;

};

#endif //__MOVE_HEADER__