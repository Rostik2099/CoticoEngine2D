#include "TestActor.h"
#include "Core/World.h"
#include "Components/SpriteComponent.h"
#include "Components/CameraComponent.h"

TestActor::TestActor()
{
	sprite = SpawnComponent<SpriteComponent>();
	sprite->SetLayer("1Player");
	camera = SpawnComponent<CameraComponent>();

	sprite->SetTexture("Content/Sprites/julia.jpg");
	sprite->SetScale(CVector(0.1f, 0.1f));
}

void TestActor::SetupInputs(InputManager* inputManager)
{
	inputManager->BindAxis("MoveForward", this, &TestActor::MoveForward);
	inputManager->BindAxis("MoveRight", this, &TestActor::MoveRight);
}

void TestActor::Tick(float dt)
{
	CActor::Tick(dt);

}

void TestActor::MoveForward(float scale)
{
	CVector NewLoc = GetActorLocation() + CVector(0.f, scale * Speed * GetDeltaTime());
	SetActorLocation(NewLoc);
}

void TestActor::MoveRight(float scale)
{
	CVector NewLoc = GetActorLocation() + CVector(scale * Speed * GetDeltaTime(), 0.f);
	SetActorLocation(NewLoc);
}
