#include "../headers/Object.hpp"

Object::Object()
{
	element_index = Elements::getInstance().RegisterObject(this);
}

Object::~Object()
{
	Elements::getInstance().UnregisterObject(element_index);
}