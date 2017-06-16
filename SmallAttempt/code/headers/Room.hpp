#ifndef __ROOM_HEADER__
#define __ROOM_HEADER__

#include "Vector2.hpp"
#include "Elements.hpp"

class Room
{

public:

	int		width;
	int		height;
	Vector2 position;
	Vector2 center;

public:

	Room()
	{

	}

	Room(int x, int y, int w, int h):
		width(w) , height(h)
	{
		position = Vector2(x, y);
		center = Vector2(x + w / 2.0f, y + h / 2.0f);
	}

	~Room();

	Room* Subdivide()
	{
		Room subdivided_rooms[2];

		if (Elements::basic_random() == 0)
		{
			Room room0 = Room(this->position.x, this->position.y, Elements::getInstance().RandomInt(0, this->width), this->height);
			Room room1 = Room(this->position.x + room0.width, this->position.y, this->width - room0.width, this->height);
			subdivided_rooms[0] = room0;
			subdivided_rooms[1] = room1;
		}
		else
		{
			Room room0 = Room(this->position.x, this->position.y, this->width, Elements::getInstance().RandomInt(0, this->height));
			Room room1 = Room(this->position.x, this->position.y + room0.height, this->width, this->height - room0.height);
			subdivided_rooms[0] = room0;
			subdivided_rooms[1] = room1;
		}

		return subdivided_rooms;
	}

private:

};

#endif //__ROOM_HEADER__
