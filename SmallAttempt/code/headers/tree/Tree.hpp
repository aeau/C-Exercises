#ifndef __TREE_HEADER__
#define __TREE_HEADER__

#include "Node.hpp"
#include "../Room.hpp"


class Tree
{
public:

	Node * root;
	Room * main_container;

public:

	Tree() 
	{
		root = new Node();
	}
	~Tree() 
	{
		delete root;
	}
	
	void CreateDungeon(int iteration, Room * main)
	{
		main_container = main;
		root->Execute(main_container, iteration);
	}

	void FillMainMap()
	{
		std::vector<Room*> leaves = root->GetLeaves();
		main_container = root->main;
		
		for (std::vector<Room *>::iterator it = leaves.begin(); it != leaves.end(); ++it)
		{
			if ((*it) != nullptr)
			{
				int _init_x = (*it)->position.x;
				int _init_y = (*it)->position.y;

				for (int y = (*it)->position.y; y < (*it)->position.y + (*it)->height; ++y)
				{
					for (int x = (*it)->position.x; x < (*it)->position.x + (*it)->width; ++x)
					{
						main_container->part[x + main_container->width * y] = (*it)->part[(x - _init_x) + (*it)->width * (y - _init_y)];
					}
				}
			}
		}
	}

	void PrintMap()
	{
		for (int y = 0; y != main_container->height; y++)
		{
			for (int x = 0; x != main_container->width; x++)
			{
				std::cout << main_container->part[x + main_container->width * y];
				//map[x + width * y] = EMPTY_CHARACTER;
			}

			std::cout << std::endl;
		}
	}


private:

};

#endif //__TREE_HEADER__