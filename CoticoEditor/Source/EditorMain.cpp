#include "Core/CEngine.h"
#include "Core/World.h"
#include "Input/InputManager.h"
#include "TestActor.h"
#include "ImGUI/imgui.h"
#include "ImGUI/imgui-SFML.h"

int main()
{
	CEngine* engine = CEngine::Get();
	engine->CreateAppWindow(1280, 720, "Cotico Engine 2D");
	engine->Init();

	World::Get()->SpawnActor<TestActor>();

	while (engine->IsEngineRunning())
	{
		engine->Update();
		engine->UpdateEvents();
		engine->Render();
	}

	return 0;
}
