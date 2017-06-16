#ifndef __MAP_HEADER__
#define __MAP_HEADER__

#include <vector>
#include <iostream>

class Map
{
public:
	const char EMPTY_CHARACTER = '.';

	std::vector <char> map;
	int height;
	int width;

public:
	Map(int height, int width);
	~Map();

	virtual bool Update();
	virtual void PrintMap();
	virtual void SetObjectInPosition(char obj, int x, int y);
private:

};

#endif //__MAP_HEADER__
