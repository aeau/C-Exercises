#ifndef __VECTOR_2_HEADER__
#define __VECTOR_2_HEADER__

#include <cmath> 

class Vector2
{
public:

	float x;
	float y;

public:
	Vector2()
	{
		prev_x = x = 0;
		prev_y = y = 0;
	}

	Vector2(float _x, float _y)
	{
		prev_x = x = _x;
		prev_y = y = _y;
	}

	~Vector2() 
	{

	}

	inline float ManhattanDistance(Vector2 other) {
		return (std::abs(other.x - x) + std::abs(other.y - y));
	}

	inline float EuclideanDistance(Vector2 other) {
		return std::sqrt(std::pow(other.x - x, 2) + std::pow(other.y - y, 2));
	}
	//float Dot(Vector2 other);

	inline Vector2 operator+(const Vector2 & other) { return Vector2(this->x + other.x, this->y + other.y); }
	inline Vector2 operator-(const Vector2 & other) { return Vector2(this->x - other.x, this->y - other.y); }
	inline Vector2 operator*(const float & other) { return Vector2(this->x * other, this->y * other); }
	inline Vector2 & operator+=(const Vector2 & other) { this->x += other.x; this->y += other.y; return *this; }

private:

	float prev_x;
	float prev_y;

};

#endif //__VECTOR_2_HEADER__