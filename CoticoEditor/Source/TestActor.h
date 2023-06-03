#pragma once
#include "Core/CActor.h"

class SpriteComponent;
class CameraComponent;

class TestActor : public CActor
{
public:
	TestActor();

	void SetupInputs(InputManager* inputManager) override;
	void Tick(float dt) override;

	void MoveForward(float scale);
	void MoveRight(float scale);

protected:
	Ref<SpriteComponent> sprite;
	Ref<CameraComponent> camera;
	float Speed = 200.f;
};

