#include "CEngine.h"
#include "CActor.h"
#include "World.h"
#include "Render/Renderer.h"
#include "Input/InputManager.h"
#include "Components/SpriteComponent.h"
#include "AppWindow/AppWindow.h"
#include "EditorUI/EditorUIManager.h"

void CEngine::Init()
{
	RenderManager = Renderer::Get();
	Input = InputManager::Get();
	CurrentWorld = World::Get();
	EditorUIManager::Get();

	CurrentCamera = new sf::View(sf::FloatRect(0, 0, 1280, 720));
}

void CEngine::Render()
{
	RenderManager->Render(CurrentWindow->GetSFWindow());
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
		EditorUIManager::Get()->ProcessEvents(event);
	}

	Input->UpdateInputs();
	EditorUIManager::Get()->Update();
}

void CEngine::Update()
{
	CurrentWorld->Tick(DeltaClock.restart().asSeconds());
}

void CEngine::CreateAppWindow(int width, int height, std::string title)
{
	this->CurrentWindow = new AppWindow(width, height, title);
}

bool CEngine::IsEngineRunning()
{
	return CurrentWindow->GetSFWindow()->isOpen();
}

CEngine::~CEngine()
{
	EditorUIManager::Get()->ShutDown();
}
