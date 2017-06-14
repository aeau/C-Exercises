#ifndef __ELEMENTS_HEADER__
#define __ELEMENTS_HEADER__

#include <memory>
#include <vector>
#include <windows.h>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "Object.hpp"

class Object;

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

private:

	Elements() 
	{
		starting_time = std::chrono::system_clock::now().time_since_epoch();
		//SetQuit(false);
	};

	~Elements() { game_objects.clear(); }

	Elements(Elements const&) = delete;
	void operator = (Elements const&) = delete;

	void UpdateMap();

	std::vector <char>			map;
	std::vector <Object*>		game_objects;	
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

	inline void RegisterObject(Object * obj)
	{
		game_objects.push_back(obj);
	}

	void CreateMap();
	void GameLoop();
};

#endif //__ELEMENTS_HEADER__