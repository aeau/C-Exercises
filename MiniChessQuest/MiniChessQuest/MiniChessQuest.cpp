// MiniChessQuest.cpp : Defines the entry point for the console application.
//

#include "code\header\Game.hpp"
#include <iostream>
#include <bitset>
#include <cmath>
#include <list>

int main()
{
	//https://projecteuler.net/problem=501
	//std::list<long> numbs;
	//long long n = 1000000;

	//for (long long i = 100000; i < n; i++)
	//{
	//	int counter = 0;
	//	for (long long j = 1; j < n; j++)
	//	{
	//		if (counter > 8)
	//			break;

	//		if (i % j == 0)
	//		{
	//			counter++;
	//		}
	//	}

	//	if (counter == 8)
	//	{
	//		numbs.push_back(i);
	//	}
	//}

	//std::cout << numbs.size() << std::endl;


	Game * game = new Game(10, 10);
	
	game->AddGameObject("Enemy");
	game->AddGameObject("Enemy");
	game->AddGameObject("Enemy");
	game->AddGameObject("Enemy");
	game->AddGameObject("Enemy");
	game->AddGameObject("Enemy");
	game->AddGameObject("Enemy");

	while (!game->GetExit())
	{
		game->PlayerUpdate();
		game->Update();
		game->Render();
	}

	delete game;

    return 0;
}

void ProjectEuler()
{
	//unsigned int main_number = 127;
	//unsigned int carry = main_number & 1; //1 is 00000001 --> by doing the number & 1, we know if the number has a 0 
	//unsigned int result = main_number ^ 1; //number XOR 1 --> will change the last bit to 1 if 0. adding 1 to the number
	////in case the number has a 1 in the last bit then it will become 0 (substracting one)

	//std::cout << "carry = " << carry << " -- Result = " << result << std::endl;
	//std::cout << "binary representation = " << std::bitset<8>(main_number) <<
	//	" -- binary carry = " << std::bitset<8>(carry) << " -- binary result = " << std::bitset<8>(result) << " -- binary addition = "
	//	<< std::bitset<8>(1) << std::endl;

	//while (carry != 0)
	//{
	//	unsigned int new_carry = carry << 1;

	//	std::cout << "Shifted carry = " << new_carry << " -- binary = " << std::bitset<8>(new_carry) << std::endl;

	//	carry = result & new_carry;

	//	std::cout << std::bitset<8>(result) << " ^" << std::endl;
	//	std::cout << std::bitset<8>(new_carry) << std::endl;
	//	std::cout << "--------" << std::endl;
	//	result = result ^ new_carry;
	//	std::cout << std::bitset<8>(result) << std::endl;

	//}

	//std::cout << "Result = " << result << std::endl;

	//FIRST EXERCISE 1
	/*int sum = 0;

	for (int i = 0; i < 1000; ++i)
	{
	if (i % 3 == 0 || i % 5 == 0)
	{
	sum += i;
	}
	}

	std::cout << sum << std::endl;*/

	//SECOND EXERCISE 2
	//long sec = 3;
	//long sum = 2;
	//long fibo_1 = 1;
	//long fibo_2 = 2;

	//while (fibo_2 < 4000000)
	//{
	//	long aux = fibo_2;
	//	fibo_2 = fibo_1 + fibo_2;
	//	fibo_1 = aux;

	//	sec += fibo_2;

	//	if (fibo_2 % 2 == 0)
	//	{
	//		sum += fibo_2;
	//	}

	//	std::cout << fibo_2 << std::endl;
	//}

	//std::cout << sum << std::endl;

	//THIRD EXERCISE 3
	//long long n = 600851475143;

	//// Print the number of 2s that divide n
	//while (n % 2 == 0)
	//{
	//	std::cout << 2 << " ";
	//	n = n / 2;
	//}

	//// n must be odd at this point.  So we can skip 
	//// one element (Note i = i +2)
	//for (long i = 3; i <= sqrt(n); i = i + 2)
	//{
	//	// While i divides n, print i and divide n
	//	while (n%i == 0)
	//	{
	//		std::cout << i << " ";
	//		n = n / i;
	//	}
	//}

	//// This condition is to handle the case when n 
	//// is a prime number greater than 2
	//if (n > 2)
	//	std::cout << n << " ";

}