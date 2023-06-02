#pragma once
#include <string>

#include "SFML/Graphics.hpp"


class AppWindow;
class World;
class Renderer;
class InputManager;

class CEngine
{
public:
	static CEngine* Get()
	{
		static CEngine engine;
		return &engine;
	};

	void Render();
	void UpdateEvents();
	void Update();

	AppWindow* GetCurrentWindow() { return this->CurrentWindow; };
	void CreateAppWindow(int width, int height, std::string title);
	bool IsEngineRunning();

private:
	CEngine() 
	{
		Init(); 
	};

	void Init();
private:
	AppWindow* CurrentWindow;
	World* CurrentWorld;
	Renderer* RenderManager;
	InputManager* Input;

	float previousTime;
	float newTime;
};

