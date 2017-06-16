#ifndef __NODE_HEADER__
#define __NODE_HEADER__

#include "../Room.hpp"

class Room;

class Node
{
public:

	bool leaf;
	Room * main;
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
	}

	inline bool Execute(Room * piece, int iteration)
	{
		if (piece->width < 2 || piece->height < 2)
		{
			return false;
		}

		main = piece;
		main->FillRoom();

		if (iteration > 0)
		{
			left_node = new Node();
			right_node = new Node();
			auto sr = main->Subdivide();
			if (!left_node->Execute(sr[0], iteration - 1))
			{
				leaf = true;
				return true;
			}
			if(!right_node->Execute(sr[1], iteration - 1))
			{
				leaf = true;
				return true;
			}
		}
		else
		{
			leaf = true;
		}
		return true;
	}

	inline std::vector<Room*> GetLeaves()
	{
		std::vector<Room*> leaf_rooms;
		leaf_rooms.resize(20);
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

private:

};

#endif //__NODE_HEADER__