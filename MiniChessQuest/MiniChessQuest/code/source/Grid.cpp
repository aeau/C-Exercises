#include "../header/Grid.hpp"

Grid::Grid(const int _width, const int _height) : map(_width * _height)
{
	width = _width;
	height = _height;

	for (int y = 0; y < _height; ++y)
	{
		for (int x = 0; x < _width; ++x)
		{
			this->map[x + width * y] = std::make_unique<Cell>();
		}
	}
}

Grid::~Grid()
{
	map.empty();
}

void Grid::PrintGrid()
{
	//this->map[2 + width * 5]->inner = "K";
	
	PrintDefaultLine();

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			std::cout << "|" << this->map[x + width * y]->GetCell();
			//std::cout << this->map[x + width * y]->GetCell();
		}

		std::cout << "|" << std::endl;

		//divider
		PrintDefaultLine();
	}
}

void Grid::Clear()
{
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			this->map[x + width * y]->Reset();
		}
	}
}

void Grid::PrintDefaultLine()
{
	for (int x = 0; x < width * 2 + 1; ++x)
	{
		std::cout << "-";
	}
	std::cout << std::endl;

}