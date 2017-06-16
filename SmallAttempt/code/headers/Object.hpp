#ifndef __OBJECT_HEADER__
#define __OBJECT_HEADER__

#include <iostream>
#include <string>
#include "Vector2.hpp"
#include "Elements.hpp"

class Elements;

class Object
{
public:

	Object();

	~Object();
	inline virtual bool Update() 
	{ 
		return false; 
	}

public:

	Vector2 position;
	char my_symbol;

protected:

	int element_index;

};
#endif //__OBJECT_HEADER__
