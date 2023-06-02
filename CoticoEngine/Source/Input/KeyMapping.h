#pragma once
#include<unordered_map>
#include<string>
#include<SFML/Graphics.hpp>

enum ActionType
{
	IE_PRESS,
	IE_RELEASE,
};

static std::unordered_map<std::string, sf::Keyboard::Key> mapping;

class InputMapping
{
public:
	InputMapping()
	{
		mapping["W"] = sf::Keyboard::W;
		mapping["A"] = sf::Keyboard::A;
		mapping["S"] = sf::Keyboard::S;
		mapping["D"] = sf::Keyboard::D;
	};
};