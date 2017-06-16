#ifndef __TREE_HEADER__
#define __TREE_HEADER__

#include "../Room.hpp"
#include "../Elements.hpp"

class Tree
{
public:

	bool leaf;
	Room * main;
	Tree * left_node;
	Tree * right_node;

public:
	Tree() 
	{
		leaf = false;
	}
	~Tree() 
	{
		delete main;
		delete left_node;
		delete right_node;
	}


private:

};

#endif //__TREE_HEADER__