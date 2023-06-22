#include "TestActor.h"
#include "Core/World.h"
#include "Components/SpriteComponent.h"
#include "Components/CameraComponent.h"
#include "Components/CollisionBoxComponent.h"

TestActor::TestActor()
{
	sprite = SpawnComponent<SpriteComponent>();
	sprite->SetLayer("1Player");
	sprite->SetTexture("Sprites/julia.jpg");
	sprite->SetScale(CVector(0.1f, 0.1f));

	camera = SpawnComponent<CameraComponent>();

	collision = SpawnComponent<CollisionBoxComponent>();
	collision->SetCollisionBounds(CVector(142.f, 190.f));
}

void TestActor::SetupInputs(InputManager* inputManager)
{
	inputManager->BindAxis("MoveForward", this, &TestActor::MoveForward);
	inputManager->BindAxis("MoveRight", this, &TestActor::MoveRight);
}

void TestActor::BeginPlay()
{
	collision->OnCollide.AddListener(this, &TestActor::OnCollided);
}

void TestActor::Tick(float dt)
{
	CActor::Tick(dt);

	std::cout << 1.f / dt << std::endl;
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

void TestActor::OnCollided(Ref<CollisionBoxComponent> Collider)
{
	std::cout << Collider->GetUUID() << std::endl;
}
