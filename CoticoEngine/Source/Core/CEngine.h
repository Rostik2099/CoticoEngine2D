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
	CameraComponent* GetCurrentCamera() { return this->CurrentCamera; };
	void SetCamera(CameraComponent* NewCamera) { this->CurrentCamera = NewCamera; };
	void OnCurrentCameraDeleted(CameraComponent* Camera);
	sf::Time GetDeltaClock() { return this->DeltaClock.restart(); };

private:
	CEngine() {};
	~CEngine();

private:
	AppWindow* CurrentWindow = nullptr;
	World* CurrentWorld = nullptr;
	Renderer* RenderManager = nullptr;
	InputManager* Input = nullptr;
	CameraComponent* CurrentCamera = nullptr;
	CameraComponent* DefaultCamera;
	sf::Clock DeltaClock;

	float previousTime;
	float newTime;
};

