#include "../headers/Map.hpp"

Map::Map(int height, int width)
{
	this->width = width;
	this->height = height;

	for (int y = 0; y != height; y++)
	{
		for (int x = 0; x != width; x++)
		{
			map.push_back(EMPTY_CHARACTER);
		}
	}
}

Map::~Map()
{
}

bool Map::Update()
{
	return false;
}

void Map::PrintMap()
{
	for (int y = 0; y != height; y++)
	{
		for (int x = 0; x != width; x++)
		{
			std::cout << map[x + width * y];
			map[x + width * y] = EMPTY_CHARACTER;
		}

		std::cout << std::endl;
	}
}

void Map::SetObjectInPosition(char obj, int x, int y)
{
	map[x + width * y] = obj;
}