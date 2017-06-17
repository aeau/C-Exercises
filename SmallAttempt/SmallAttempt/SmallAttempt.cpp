// SmallAttempt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../code/headers/Vector2.hpp"
#include "../code/headers/Player.hpp"
#include "../code/headers/Wall.hpp"
#include "../code/headers/Map.hpp"
#include "../code/headers/tree/Tree.hpp"
#include "../code/headers/Room.hpp"

#include <iostream>
#include <string>
#include <random>
#include <cmath>
//using namespace std;

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;



int main()
{

	/*Vector2 a = Vector2(Elements::dist(random_generator), dist(random_generator));
	Vector2 b = Vector2(dist(random_generator), dist(random_generator));
	Vector2 c = Vector2();

	c = b * 0.1f;
	cout << "Vector A, x and y values are: " << a.x << ", " << a.y << endl;
	cout << "Vector B, x and y values are: " << b.x << ", " << b.y << endl;
	cout << "Vector C, x and y values are: " << c.x << ", " << c.y << endl << endl;*/

	Room * r = new Room(0, 0, 80, 40);

	Tree * t = new Tree();
	t->CreateDungeon(10, r);
	t->FillMainMap();
	t->PrintMap();

	std::string f = "";
	int pressed_key = std::getchar();

	cout << pressed_key << endl;

	while (f != "exit")
	{
		std::getline(std::cin, f);
		std::cout << "your number is " << f << std::endl;
	}
	//std::cin >> f;

	//for (int i = 0; i < 10; i++)
	//{
	//	Wall * w = new Wall(Elements::rand_pos(), Elements::rand_pos());
	//	//walls.push_back(w);
	//}

	///*Wall w1 = Wall(rand_pos(), rand_pos());
	//Wall w2 = Wall(rand_pos(), rand_pos());*/
	//Player p = Player();
	//std::shared_ptr<Map> new_map(new Map(Elements::getInstance().WIDTH, Elements::getInstance().HEIGHT));
	//Elements::getInstance().RegisterMap(new_map);
	////Elements::getInstance().CreateMap();
	//Elements::getInstance().GameLoop();
	
    return 0;
}

