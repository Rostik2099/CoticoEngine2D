#pragma once
#include <string>

#include "SFML/Graphics.hpp"


class AppWindow;
class World;
class Renderer;
class InputManager;
class CameraComponent;

class CEngine
{
public:
	static CEngine* Get()
	{
		static CEngine engine;
		return &engine;
	};

	void Init();
	void Render();
	void UpdateEvents();
	void Update();

	AppWindow* GetCurrentWindow() { return this->CurrentWindow; };
	void CreateAppWindow(int width, int height, std::string title);
	bool IsEngineRunning();
	sf::View* GetCurrentCamera() { return this->CurrentCamera; };
	void SetCamera(sf::View* NewCamera) { this->CurrentCamera = NewCamera; };
	sf::Time GetDeltaClock() { return this->DeltaClock.restart(); };

private:
	CEngine() {};
	~CEngine();

private:
	AppWindow* CurrentWindow;
	World* CurrentWorld;
	Renderer* RenderManager;
	InputManager* Input;
	sf::View* CurrentCamera;
	sf::Clock DeltaClock;

	float previousTime;
	float newTime;
};

