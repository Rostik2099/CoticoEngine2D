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

	sf::Vector2f ToSFVector() 
	{
		return sf::Vector2f(X, Y);
	};

	float X = 0;
	float Y = 0;
};