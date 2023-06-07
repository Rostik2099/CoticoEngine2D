#include "Core/CEngine.h"
#include "Core/World.h"
#include "TestActor.h"
#include "GUI/EditorGUI.h"

int main()
{
	CEngine* engine = CEngine::Get();
	engine->CreateAppWindow(1280, 720, "Cotico Engine 2D");
	engine->Init();

	World::Get()->SpawnActor<TestActor>();

	EditorGUI GUI;

	while (engine->IsEngineRunning())
	{
		engine->Update();
		engine->UpdateEvents();
		engine->Render();
	}

	return 0;
}
