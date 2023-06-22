#pragma once
#include "Core/CActor.h"

class SpriteComponent;
class CameraComponent;
class CollisionBoxComponent;

class TestActor : public CActor
{
public:
	TestActor();

	void SetupInputs(InputManager* inputManager) override;
	void BeginPlay() override;
	void Tick(float dt) override;

	void MoveForward(float scale);
	void MoveRight(float scale);

	void OnCollided(Ref<CollisionBoxComponent> Collider);

protected:
	Ref<SpriteComponent> sprite;
	Ref<CameraComponent> camera;
	Ref<CollisionBoxComponent> collision;
	float Speed = 200.f;
};

