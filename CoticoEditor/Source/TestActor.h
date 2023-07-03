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

	void CheckCollision();
	void RotateToMouse();

protected:
	Ref<SpriteComponent> sprite;
	Ref<CameraComponent> camera;
	Ref<CollisionBoxComponent> collision;

	//Movement
	float Speed = 200.f;
	int UpDir = 0;
	int RightDir = 0;
	CVector LastLocation;
};


