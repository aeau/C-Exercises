#ifndef ENTITY_HEADER
#define ENTITY_HEADER

#include "Vector2.hpp"
#include "Action.hpp"
#include <memory>
#include <list>

class Entity
{
public:

	typedef std::list<std::shared_ptr<Action>> actionSequence;
	typedef std::vector<actionSequence> actionSequences;
	actionSequences possible_actions;

	char symbol;
	mutable std::unique_ptr<Vector2> position;

private:

	actionSequences valid_actions; //TODO: CHECK HERE

public:
	Entity() {}
	~Entity() { possible_actions.clear(); }

	virtual void NextMove() = 0;
	inline virtual void SetPosition(const Vector2 & value) { position->x = value.x; position->y = value.y; }
	inline virtual void SetPosition(const int & _x, const int & _y) { position->x = _x; position->y = _y; }
	inline const virtual Vector2 & GetPosition() { return *position; }

};

#endif //ENTITY_HEADER