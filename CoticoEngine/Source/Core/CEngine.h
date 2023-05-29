#pragma once
#include <string>

#include "SFML/Graphics.hpp"

class AppWindow;

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

	void CreateAppWindow(int width, int height, std::string title);
	bool IsEngineRunning();

private:
	CEngine() {};

private:
	AppWindow* CurrentWindow;
};

