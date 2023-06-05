#pragma once

#include "imgui.h"
#include "imgui-SFML.h"

class AppWindow;

class EditorUIManager
{
public:
	static EditorUIManager* Get()
	{
		static EditorUIManager manager;
		return &manager;
	};

	void ProcessEvents(sf::Event event);
	void Update();
	void Render();
	void ShutDown();

	~EditorUIManager();

private:
	EditorUIManager();
	AppWindow* CurrentWindow;
};

