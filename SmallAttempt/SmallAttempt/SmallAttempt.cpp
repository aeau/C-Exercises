// SmallAttempt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../code/headers/Vector2.hpp"
#include "../code/headers/Player.hpp"

#include <iostream>
#include <string>
//using namespace std;

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

int main()
{
	Vector2 a = Vector2(0.7f, 2.5f);
	Vector2 b = Vector2(1.4f, 3.0f);
	Vector2 c = Vector2();

	c = b * 0.1f;

	cout << "Vector A, x and y values are: " << a.x << ", " << a.y << endl;
	cout << "Vector B, x and y values are: " << b.x << ", " << b.y << endl;
	cout << "Vector C, x and y values are: " << c.x << ", " << c.y << endl << endl;


	Player p = Player();
	Elements::getInstance().CreateMap();
	Elements::getInstance().GameLoop();





	////char f = ' ';
	//std::string f = "";
	//int pressed_key = std::getchar();

	//cout << pressed_key << endl;

	//while (f != "exit")
	//{
	//	std::getline(std::cin, f);
	//	std::cout << "your number is " << f << std::endl;
	//}
	////std::cin >> f;
    return 0;
}

