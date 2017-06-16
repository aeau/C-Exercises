#include "../headers/Elements.hpp"

std::random_device Elements::rd;
std::mt19937 Elements::random_generator(Elements::rd());
std::uniform_int_distribution<int> Elements::dist(1, 9);
std::uniform_int_distribution<int> Elements::zero_one(0, 1);
std::_Binder<std::_Unforced, std::uniform_int_distribution<int> &, std::mt19937 &> Elements::rand_pos = std::bind(Elements::dist, Elements::random_generator);
std::_Binder<std::_Unforced, std::uniform_int_distribution<int> &, std::mt19937 &> Elements::basic_random = std::bind(Elements::zero_one, Elements::random_generator);

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
		std::cout << "Elements to update: " << game_objects.size() << std::endl;


		UpdateMap();
		

		for (std::vector<Object *>::iterator it = game_objects.begin(); it != game_objects.end(); ++it)
		{	
			bool done = true;
			if ((*it) != nullptr)
			{
				//std::thread update_thread(&Object::Update, (*it));
				//std::mutex mutex_object;
				//std::unique_lock<std::mutex> lock(mutex_object);

				//while (thread_conditional.wait_for(lock, std::chrono::seconds(2)) == std::cv_status::timeout)
				//{
				//	//update_thread.detach();
				//	lock.unlock();
				//	std::cin.clear();
				//	//fflush(stdin);
				//	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				//	//lock.release();
				//	//mutex_object.unlock();
				//	//std::terminate();
				//	done = false;
				//	break;
				//}

				//if(done)
				//	update_thread.join();

				quit = (*it)->Update();

				if (quit) break;
			}
		}

		last_udpate = current_time;
	}
}

void Elements::UpdateMap()
{
	for (std::vector<Object *>::iterator it = game_objects.begin(); it != game_objects.end(); ++it)
	{
		if ((*it) != nullptr)
		{
			Vector2 p = (*it)->position;
			current_map->SetObjectInPosition((*it)->my_symbol, p.x, p.y);
			//map[p.x + WIDTH * p.y] = (*it)->my_symbol;
		}
	}

	current_map->PrintMap();
}