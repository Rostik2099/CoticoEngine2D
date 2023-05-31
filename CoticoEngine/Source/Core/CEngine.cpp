#include "CEngine.h"
#include "CActor.h"
#include "World.h"
#include "Render/Renderer.h"
#include "Components/SpriteComponent.h"
#include "AppWindow/AppWindow.h"

void CEngine::Init()
{
	RenderManager = Renderer::Get();
	CurrentWorld = World::Get();
	Ref<CActor> Act = CurrentWorld->SpawnActor<CActor>();
	Ref<SpriteComponent> Comp = Act->SpawnComponent<SpriteComponent>();
	Comp->SetTexture("Content/Sprites/julia.jpg");
	Comp->SetScale(CVector(0.25f, 0.25f));
	Act->Destroy();
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
	}
}

void CEngine::Update()
{
	sf::Clock deltaClock;
	previousTime = newTime;
	newTime = deltaClock.restart().asMilliseconds();

	float dt = (newTime - previousTime);

	CurrentWorld->Tick(dt);
}

void CEngine::CreateAppWindow(int width, int height, std::string title)
{
	this->CurrentWindow = new AppWindow(width, height, title);
}

bool CEngine::IsEngineRunning()
{
	return CurrentWindow->GetSFWindow()->isOpen();
}
