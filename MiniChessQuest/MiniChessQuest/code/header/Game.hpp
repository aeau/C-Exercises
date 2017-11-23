#ifndef GAME_HEADER
#define GAME_HEADER

#include <memory>
#include <list>
#include <vector>
#include <string>
#include <random>
#include <iostream>

#include "Grid.hpp"
#include "Entity.hpp"
#include "Enemy.hpp"

class Game
{
public:
	typedef std::list<std::unique_ptr<Entity>> l_GameObjects;

	std::unique_ptr<Grid> grid; //Grid of the game
	l_GameObjects gameobjects; //Current gameobjects in the game
	int current_move; //How many moves have we done

public:
	Game(const int width, const int height);
	~Game();

	void PlayerUpdate();
	void Update();
	void Render();
	void AddGameObject(const std::string & type);
	
	inline bool GetExit() { return m_exit; }

private:

	bool m_exit; //should we exit the game?
	int width;
	int height;

	//For randoms
	std::mt19937 random_generator;

};


#endif //GAME_HEADER