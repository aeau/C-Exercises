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

	Object()
	{
		//Elements::getInstance().RegisterObject(this);
	}

	~Object() {}
	virtual bool Update() 
	{ 
		return false; 
	}

public:

	Vector2 position;
	char my_symbol;

};
#endif //__OBJECT_HEADER__
