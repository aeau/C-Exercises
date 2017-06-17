#ifndef __NODE_HEADER__
#define __NODE_HEADER__

#include "../Room.hpp"

class Room;

class Node
{
public:

	const int MINIMUN_HEIGHT = 8;
	const int MINIMUN_WIDTH = 8; 

	bool leaf;
	Room * main;
	Room * corridor;
	Node * left_node;
	Node * right_node;

public:

	Node()
	{
		leaf = false;
	}
	~Node()
	{
		delete main;
		delete left_node;
		delete right_node;
		delete corridor;
	}

	inline bool Execute(Room * piece, int iteration)
	{
		bool subdivision = false;
		int tries = 5;

		if (piece->width < MINIMUN_WIDTH || piece->height < MINIMUN_HEIGHT)
		{
			return false;
		}

		main = piece;
		main->FillRoom();

		while (!subdivision && tries-- > 0)
		{
			subdivision = true;
			if (iteration > 0)
			{
				left_node = new Node();
				right_node = new Node();
				auto sr = main->Subdivide();
				if (!left_node->Execute(sr[0], iteration - 1))
				{
					subdivision = false;
					/*leaf = true;
					return true;*/
				}

				if (subdivision && !right_node->Execute(sr[1], iteration - 1))
				{
					subdivision = false;
					/*leaf = true;
					return true;*/
				}
			}
			else
			{
				leaf = true;
				return true;
			}
		}
		
		if (!subdivision)
		{
			leaf = true;
			return true;
		}

		if (left_node->main->position.x == right_node->main->position.x)
		{
			corridor = new Room(left_node->main->center.x, left_node->main->center.y, 1, std::abs(left_node->main->center.y - right_node->main->center.y));
		}
		else
		{
			corridor = new Room(left_node->main->center.x, left_node->main->center.y, std::abs(left_node->main->center.x - right_node->main->center.x), 1);
		}

		corridor->FillCorridor();

		return true;
	}

	inline std::vector<Room*> GetLeaves()
	{
		std::vector<Room*> leaf_rooms;
		leaf_rooms.resize(200);
		if(!leaf)
		{
			std::vector<Room*> left_leaves = left_node->GetLeaves();
			std::vector<Room*> right_leaves = right_node->GetLeaves();

			leaf_rooms.insert(leaf_rooms.end(), left_leaves.begin(), left_leaves.end());
			leaf_rooms.insert(leaf_rooms.end(), right_leaves.begin(), right_leaves.end());
		}
		else
		{
			leaf_rooms.push_back(main);
		}

		return leaf_rooms;
	}

	inline std::vector<Room*> GetCorridors()
	{
		std::vector<Room*> corridors;
		corridors.resize(200);

		if (!leaf)
		{
			corridors.push_back(corridor);
			std::vector<Room*> left_corridors = left_node->GetCorridors();
			std::vector<Room*> right_corridors = right_node->GetCorridors();

			corridors.insert(corridors.end(), left_corridors.begin(), left_corridors.end());
			corridors.insert(corridors.end(), right_corridors.begin(), right_corridors.end());
		}

		return corridors;
	}

private:

};

#endif //__NODE_HEADER__