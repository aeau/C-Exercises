#ifndef __RANDOM_HEADER__
#define __RANDOM_HEADER__

#include <random>
#include "Vector2.hpp"

namespace Basic
{
	class Random
	{

	public:

		static Random & getInstance()
		{
			static Random instance;
			return instance;
		}

	private:
		Random() : random_generator(rd())
		{
			//random_generator(rd()); 
		};

		~Random() {};

		Random(Random const&) = delete;
		void operator = (Random const&) = delete;

	public:

		inline int RandomInt(int max, int min = 0)
		{
			std::uniform_int_distribution<int> aux(min, max);
			return aux(Random::random_generator);
		}

		inline float RandomFloat(float max, float min = 0.0f)
		{
			std::uniform_real_distribution<float> aux(min, max);
			return aux(Random::random_generator);
		}

		inline Vector2 RandomUnitVector2()
		{
			std::uniform_real_distribution<float> _x(0.0f, 1.0f);
			std::uniform_real_distribution<float> _y(0.0f, 1.0f);

			return Vector2(_x(Random::random_generator), _y(Random::random_generator));
		}

		inline Vector2 RandomVector2(int max_x, int max_y, int min_x = 0, int min_y = 0)
		{
			std::uniform_int_distribution<int> _x(min_x, max_x);
			std::uniform_int_distribution<int> _y(min_y, max_y);

			return Vector2(_x(Random::random_generator), _y(Random::random_generator));
		}

	public:

		//For randoms
		std::mt19937 random_generator;
		std::random_device rd;

	};
}

#endif //__RANDOM_HEADER__

	//std::mt19937 Random::random_generator(Random::rd());