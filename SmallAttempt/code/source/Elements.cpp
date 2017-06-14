#include "../headers/Elements.hpp"

void Elements::CreateMap()
{
	for (int y = 0; y != HEIGHT; y++)
	{
		for (int x = 0; x != WIDTH; x++)
		{
			map.push_back(EMPTY_CHARACTER);
		}
	}
}

void Elements::GameLoop()
{
	while (!quit)
	{

		clear_screen();
		UpdateMap();

		for (int y = 0; y != HEIGHT; y++)
		{
			for (int x = 0; x != WIDTH; x++)
			{
				std::cout << map[x + WIDTH * y];
			}

			std::cout << std::endl;
		}

		for (std::vector<Object *>::iterator it = game_objects.begin(); it != game_objects.end(); ++it)
		{
			if ((*it) != nullptr)
			{
				quit = (*it)->Update();
				if (quit) break;
			}
		}
	}
}

void Elements::UpdateMap()
{
	for (int y = 0; y != HEIGHT; y++)
	{
		for (int x = 0; x != WIDTH; x++)
		{
			map[x + WIDTH * y] = EMPTY_CHARACTER;
		}
	}

	for (std::vector<Object *>::iterator it = game_objects.begin(); it != game_objects.end(); ++it)
	{
		if ((*it) != nullptr)
		{
			Vector2 p = (*it)->position;
			map[p.x + WIDTH * p.y] = (*it)->my_symbol;
		}
	}
}