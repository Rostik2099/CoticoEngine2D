#include "TestActor.h"
#include "Core/World.h"
#include "Components/SpriteComponent.h"
#include "Components/CameraComponent.h"

TestActor::TestActor()
{
	sprite = SpawnComponent<SpriteComponent>();
	camera = SpawnComponent<CameraComponent>();
	camera->SetLocalOffset(CVector(320.f, 200.f));

	Ref<CActor> act = GetWorld()->SpawnActor<CActor>();
	act->SetActorLocation(CVector(100.f, 200.f));
	Ref<SpriteComponent> comp = act->SpawnComponent<SpriteComponent>();
	act->SetCompsOwner();
	comp->SetTexture("Content/Sprites/unnamed.png");
	comp->SetScale(CVector(0.25f));

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
