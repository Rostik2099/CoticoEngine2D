#include "Core/CEngine.h"

int main()
{
	CEngine* engine = CEngine::Get();

	engine->CreateAppWindow(1280, 720, "Cotico Engine 2D");

	while (engine->IsEngineRunning())
	{
		engine->UpdateEvents();
		engine->Update();
		engine->Render();
	}

	return 0;
}
