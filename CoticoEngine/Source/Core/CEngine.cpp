#include "CEngine.h"
#include "AppWindow/AppWindow.h"

void CEngine::Render()
{
	CurrentWindow->GetSFWindow()->clear(sf::Color::Red);
	sf::RectangleShape rect(sf::Vector2f(128.f, 128.f));
	CurrentWindow->GetSFWindow()->draw(rect);
	CurrentWindow->GetSFWindow()->display();
}

void CEngine::UpdateEvents()
{
	sf::Event event;
	while (CurrentWindow->GetSFWindow()->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			CurrentWindow->CloseWindow();
		}
	}
}

void CEngine::Update()
{
}

void CEngine::CreateAppWindow(int width, int height, std::string title)
{
	this->CurrentWindow = new AppWindow(width, height, title);
}

bool CEngine::IsEngineRunning()
{
	return CurrentWindow->GetSFWindow()->isOpen();
}
