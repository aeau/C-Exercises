#ifndef ENTITY_HEADER
#define ENTITY_HEADER

#include "Vector2.hpp"
#include <memory>

class Entity
{
public:

	char symbol;
	std::unique_ptr<Vector2> position;

public:
	Entity();
	~Entity();

	virtual void NextMove() = 0;
	inline virtual void SetPosition(const Vector2 & value) { position->x = value.x; position->y = value.y; }
	inline virtual void SetPosition(const int & _x, const int & _y) { position->x = _x; position->y = _y; }
	inline const virtual Vector2 & GetPosition() { return *position; }

private:

};

#endif //ENTITY_HEADER