#include "../header/Move.hpp"
#include "../header/Entity.hpp"

Move::Move(const float & x, const float & y)
{
	additive = Vector2(x, y);
}

Move::Move(const Vector2 & xy)
{
	additive = xy;
}

Move::~Move()
{

}

void Move::Perform(Entity & owner)
{
	owner.SetPosition(additive + owner.GetPosition());
}

///Test if the move is actually valid
bool Move::Test(Grid & current_map, Entity & owner)
{
	Vector2 np = additive + owner.GetPosition();

	//true if position is inside the grid and the end pos is not one of the impassable characters (e.g. # --> wall)
	return np.x < current_map.width || np.x >= 0 || np.y < current_map.height || np.y >= 0 || error_chars.find(current_map.GetCell(np)) == std::string::npos;
}