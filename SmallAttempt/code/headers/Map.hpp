#ifndef __MAP_HEADER__
#define __MAP_HEADER__

#include <vector>
#include "Object.hpp"

class Map : Object
{
public:

	std::vector<int> map;

public:
	Map();
	~Map();

	virtual bool Update() override;

private:

};

#endif //__MAP_HEADER__
