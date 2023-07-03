#pragma once
#include <SFML/Graphics.hpp>

class CVector 
{
public:
	CVector() {};

	CVector(float x, float y) 
	{
		this->X = x;
		this->Y = y;
	};

	CVector(float x)
	{
		this->X = x;
		this->Y = x;
	};

	CVector(sf::Vector2f vec)
	{
		this->X = vec.x;
		this->Y = vec.y;
	};

	CVector(sf::Vector2i vec)
	{
		this->X = vec.x;
		this->Y = vec.y;
	};

	sf::Vector2f ToSFVector() 
	{
		return sf::Vector2f(X, Y);
	};

	CVector operator+ (CVector rhs) 
	{
		return CVector(X + rhs.X, Y + rhs.Y);
	};

	CVector operator- (CVector rhs)
	{
		return CVector(X - rhs.X, Y - rhs.Y);
	};

	CVector operator* (CVector rhs)
	{
		return CVector(X * rhs.X, Y * rhs.Y);
	};

	CVector operator* (float rhs)
	{
		return CVector(X * rhs, Y * rhs);
	};
	
	CVector operator/ (CVector rhs)
	{
		return CVector(X / rhs.X, Y / rhs.Y);
	};

	CVector operator/ (float rhs)
	{
		return CVector(X / rhs, Y / rhs);
	};

	float X = 0;
	float Y = 0;
};