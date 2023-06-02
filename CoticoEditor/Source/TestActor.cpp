#include "TestActor.h"
#include "Components/SpriteComponent.h"

TestActor::TestActor()
{
	sprite = SpawnComponent<SpriteComponent>();

	sprite->SetTexture("Content/Sprites/julia.jpg");
	sprite->SetScale(CVector(0.25f, 0.25f));
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
	sprite->GetSprite().move(CVector(0.f, 200.f * scale).ToSFVector());
}

void TestActor::MoveRight(float scale)
{
	sprite->GetSprite().move(CVector(3.f * scale, 0.f).ToSFVector());
}
