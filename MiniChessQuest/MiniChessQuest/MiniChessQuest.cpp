// MiniChessQuest.cpp : Defines the entry point for the console application.
//

#include "code\header\Game.hpp"
#include <iostream>
#include <bitset>
#include <cmath>

struct Vector3D
{
	float x, y, z;

	Vector3D(float x, float y, float z)
	{ 
		this->x = x; 
		this->y = y; 
		this->z = z;
	}

	Vector3D operator-(Vector3D const & other) { return Vector3D(this->x - other.x, this->y - other.y, this->z - other.z); }
	Vector3D operator*(float const & scale) { return Vector3D(this->x * scale, this->y * scale, this->z * scale); }

};

Vector3D & GetNormalised_Vector(Vector3D & u, Vector3D & v)
{
	Vector3D result = v - u; //vector between 
	float length = 1/sqrt(result.x * result.x + result.y * result.y + result.z * result.z); //it is avoided to perform division in each of the components
	float magnitude = sqrt(result.x * result.x + result.y * result.y + result.z * result.z);


	std::cout << "inverse square root = " << length << std::endl;
	std::cout << "magnitude = " << magnitude << std::endl;


	result = result * length; //multiply all the components by a scalar.

	return result;
}

Vector3D & Getother(Vector3D & u, Vector3D & v)
{
	Vector3D result = Vector3D(0, 0, 0);
	
	result.x = v.x - u.x;
	result.y = v.y - u.y;
	result.z = v.z - u.z;

	float length = sqrt(result.x * result.x + result.y * result.y + result.z * result.z);

	result.x /= length;
	result.y /= length;
	result.z /= length;

	return result;
}

int main()
{
	Vector3D u = Vector3D(3, 5, 7);
	//u.x = 3;
	//u.y = 5;
	//u.z = 7;

	Vector3D v = Vector3D(9, 2, 15);
	//v.x = 9;
	//v.y = 2;
	//v.z = 15;

	Vector3D r = GetNormalised_Vector(u, v);
	Vector3D r_other = Getother(u, v);

	std::cout << "U --> X = " << u.x << ", Y = " << u.y << ", Z = " << u.z << std::endl;
	std::cout << "V --> X = " << v.x << ", Y = " << v.y << ", Z = " << v.z << std::endl;
	std::cout << "R --> X = " << r.x << ", Y = " << r.y << ", Z = " << r.z << std::endl;
	std::cout << "R_other --> X = " << r_other.x << ", Y = " << r_other.y << ", Z = " << r_other.z << std::endl;



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

	/*Game * game = new Game(10, 10);
	
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

	delete game;*/

    return 0;
}