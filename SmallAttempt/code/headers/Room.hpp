#ifndef __ROOM_HEADER__
#define __ROOM_HEADER__

#include "Vector2.hpp"
#include "Elements.hpp"
#include <vector>

class Room
{

public:

	int		width;
	int		height;
	Vector2 position;
	Vector2 center;
	std::vector<char> part;

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

	~Room()
	{
		part.clear();
	}

	std::vector<Room *> Subdivide()
	{

		std::vector<Room *> subdivided_rooms;

		if (Elements::basic_random() == 0)
		{
			Room * room0 = new Room(this->position.x, this->position.y, Elements::getInstance().RandomInt(0, this->width -1), this->height);
			Room * room1 = new Room(this->position.x + room0->width, this->position.y, this->width - room0->width, this->height);
			subdivided_rooms.push_back(room0);
			subdivided_rooms.push_back(room1);
		}
		else
		{
			Room * room0 = new Room(this->position.x, this->position.y, this->width, Elements::getInstance().RandomInt(0, this->height - 1));
			Room * room1 = new Room(this->position.x, this->position.y + room0->height, this->width, this->height - room0->height);
			subdivided_rooms.push_back(room0);
			subdivided_rooms.push_back(room1);
		}

		return subdivided_rooms;
	}

	void FillRoom()
	{
		for (int y = 0; y != height; y++)
		{
			for (int x = 0; x != width; x++)
			{
				if(x == 0|| x == width - 1 || y ==0   || y == height -1 )
				{
					part.push_back('w');
				}
				else
				{
					part.push_back('.');
				}
			}
		}
	}

private:

};

#endif //__ROOM_HEADER__
