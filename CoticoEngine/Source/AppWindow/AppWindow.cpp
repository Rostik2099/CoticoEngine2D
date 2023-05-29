#include "AppWindow.h"

AppWindow::AppWindow(int width, int height, std::string title)
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	window->setFramerateLimit(60);
}

void AppWindow::CloseWindow()
{
	window->close();
}
