#pragma once
#include<string>

#include "SFML/Graphics.hpp"

class AppWindow
{
public:
	AppWindow(int width, int height, std::string title);

	sf::RenderWindow* GetSFWindow() { return this->window; };
	void CloseWindow();
		
private:
	sf::RenderWindow* window;
};

