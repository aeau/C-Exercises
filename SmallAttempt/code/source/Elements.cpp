#include "../headers/Elements.hpp"

void Elements::CreateMap()
{
	for (int y = 0; y != HEIGHT; y++)
	{
		for (int x = 0; x != WIDTH; x++)
		{
			map.push_back(EMPTY_CHARACTER);
		}
	}
}

void Elements::GameLoop()
{
	while (!quit)
	{
		current_time = std::chrono::system_clock::now().time_since_epoch() - starting_time;
		deltatime = std::abs(current_time.count() - last_udpate.count());

		clear_screen();

		std::cout << "current " << current_time.count() << std::endl;
		std::cout << "last: " << last_udpate.count() << std::endl;
		std::cout << "DELTA TIME: " << deltatime << std::endl;


		UpdateMap();

		for (int y = 0; y != HEIGHT; y++)
		{
			for (int x = 0; x != WIDTH; x++)
			{
				std::cout << map[x + WIDTH * y];
			}

			std::cout << std::endl;
		}

		for (std::vector<Object *>::iterator it = game_objects.begin(); it != game_objects.end(); ++it)
		{
			
			bool done = true;
			if ((*it) != nullptr)
			{
				std::thread update_thread(&Object::Update, (*it));
				std::mutex mutex_object;
				std::unique_lock<std::mutex> lock(mutex_object);

				while (thread_conditional.wait_for(lock, std::chrono::seconds(2)) == std::cv_status::timeout)
				{
					//update_thread.detach();
					lock.unlock();
					std::cin.clear();
					//fflush(stdin);
					//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					//lock.release();
					//mutex_object.unlock();
					//std::terminate();
					done = false;
					break;
				}

				if(done)
					update_thread.join();

				//quit = (*it)->Update();

				if (quit) break;
			}
		}

		last_udpate = current_time;

	}
}

void Elements::UpdateMap()
{
	for (int y = 0; y != HEIGHT; y++)
	{
		for (int x = 0; x != WIDTH; x++)
		{
			map[x + WIDTH * y] = EMPTY_CHARACTER;
		}
	}

	for (std::vector<Object *>::iterator it = game_objects.begin(); it != game_objects.end(); ++it)
	{
		if ((*it) != nullptr)
		{
			Vector2 p = (*it)->position;
			map[p.x + WIDTH * p.y] = (*it)->my_symbol;
		}
	}
}