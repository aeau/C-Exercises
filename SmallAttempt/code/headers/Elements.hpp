#ifndef __ELEMENTS_HEADER__
#define __ELEMENTS_HEADER__

#include <memory>
#include <vector>
#include <windows.h>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>
#include <cmath>
#include "Object.hpp"
#include "Map.hpp"

class Object;
class Map;

class Elements
{
public:

	const int WIDTH = 10;
	const int HEIGHT = 10;
	const char EMPTY_CHARACTER = '.';

	static Elements &getInstance()
	{
		static Elements instance;
		return instance;
	}

	float deltatime;
	std::condition_variable thread_conditional;

	static std::random_device rd;
	static std::mt19937 random_generator;
	static std::uniform_int_distribution<int> dist;
	static std::uniform_int_distribution<int> zero_one;
	static std::_Binder<std::_Unforced, std::uniform_int_distribution<int> &, std::mt19937 &> rand_pos;
	static std::_Binder<std::_Unforced, std::uniform_int_distribution<int> &, std::mt19937 &> basic_random;

private:

	Elements() 
	{
		starting_time = std::chrono::system_clock::now().time_since_epoch();
		game_objects.clear();
		//SetQuit(false);
	};

	~Elements() { game_objects.clear(); }

	Elements(Elements const&) = delete;
	void operator = (Elements const&) = delete;

	void UpdateMap();

	std::shared_ptr<Map>						current_map;
	std::vector <Object*>						game_objects;
	std::chrono::duration<double, std::milli>	starting_time;
	std::chrono::duration<double, std::milli>	current_time;
	std::chrono::duration<double, std::milli>	last_udpate;


	/*std::shared_ptr < Material >        material_in_use;
	Camera_GameObject *                 camera_in_game;
	Window *                            window_in_use;*/

	bool quit = false;

public:

	void clear_screen(char fill = ' ') {
		COORD tl = { 0,0 };
		CONSOLE_SCREEN_BUFFER_INFO s;
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(console, &s);
		DWORD written, cells = s.dwSize.X * s.dwSize.Y;
		FillConsoleOutputCharacter(console, fill, cells, tl, &written);
		FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
		SetConsoleCursorPosition(console, tl);
	}

	inline void RegisterMap(std::shared_ptr<Map> m) { current_map = m; }

	inline int RegisterObject(Object * obj)
	{
		game_objects.push_back(obj);
		return game_objects.size() - 1;
	}

	inline void UnregisterObject(int obj_index)
	{
		game_objects.erase(game_objects.begin() + obj_index);
	}

	int RandomInt(int min, int max)
	{
		std::uniform_int_distribution<int> aux(min, max);
		return aux(Elements::random_generator);
	}

	void GameLoop();
};

#endif //__ELEMENTS_HEADER__