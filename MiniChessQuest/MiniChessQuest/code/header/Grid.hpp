#ifndef GRID_HEADER
#define GRID_HEADER

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "Cell.hpp"
#include "Vector2.hpp"

class Grid
{
public:

	std::vector<std::unique_ptr<Cell>> map;
	int width;
	int height;

public:
	Grid(const int width, const int height);
	~Grid();

	void PrintGrid();
	void Clear();
	inline void SetCell(const int & _x, const int & _y, const char s) { map[_x + width * _y]->inner = s; }
	inline void SetCell(const Vector2 & pos, const char s) { map[pos.x + width * pos.y]->inner = s; }
	inline const char & GetCell(const Vector2 & pos) { return map[pos.x + width * pos.y]->GetCell(); }

private:
	void PrintDefaultLine();

};



#endif //GRID_HEADER