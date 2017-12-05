// MiniChessQuest.cpp : Defines the entry point for the console application.
//

#include "code\header\Game.hpp"
#include <iostream>
#include <bitset>
#include <cmath>

int main()
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