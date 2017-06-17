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

	int		actual_room_width;
	int		actual_room_height;
	Vector2 actual_room_position;

public:

	Room()
	{

	}

	Room(int x, int y, int w, int h):
		width(w) , height(h)
	{
		position = Vector2(x, y);
		center = Vector2(x + w / 2.0f, y + h / 2.0f);

		actual_room_position = Vector2(x + Elements::getInstance().RandomInt(0, (w - 1) / 4), y + Elements::getInstance().RandomInt(0, (h - 1) / 4));
		actual_room_width = w - (actual_room_position.x - x);
		actual_room_height = h - (actual_room_position.y - y);
		actual_room_width -= Elements::getInstance().RandomInt(0, (actual_room_width - 1) / 3);
		actual_room_height -= Elements::getInstance().RandomInt(0, (actual_room_height - 1) / 3);
	}

	Room(int x, int y, int w, int h, int r_w, int r_h, std::vector<char*> map) :
		width(w), height(h)
	{
		position = Vector2(x, y);
		center = Vector2(x + w / 2.0f, y + h / 2.0f);
		part.resize(w * h);

		//for (int _y = 0; _y != height; _y++)
		//{
		//	for (int _x = 0; _x != width; _x++)
		//	{
		//		part[_x * width + _y] = map[(x + _x) * r_w + (y + _y)];
		//	}
		//}
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
					part.push_back(' ');
				}
				else
				{
					part.push_back(' ');
				}
			}
		}

		int init_y = actual_room_position.y - position.y;
		int init_x = actual_room_position.x - position.x;

		for (int y = init_y; y != actual_room_height; y++)
		{
			for (int x = init_x; x != actual_room_width; x++)
			{
				if (x == init_x || x == actual_room_width - 1 || y == init_y || y == actual_room_height - 1)
				{
					part[x + width * y] = 'w';
				}
				else
				{
					part[x + width * y] = '.';

				}
			}
		}

	}

	void FillCorridor()
	{
		for (int y = 0; y != height; y++)
		{
			for (int x = 0; x != width; x++)
			{
				part.push_back('+');
			}
		}
	}

private:

};

#endif //__ROOM_HEADER__
