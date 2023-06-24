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
	collision->SetCollisionState(Dynamic);
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
	CVector BoxOffset = Collider->GetCollisionBoxBounds() / 2.f;
	CVector PlayerOffset = collision->GetCollisionBoxBounds() / 2.f;
	CVector DistanceOrig = GetActorLocation() - Collider->GetWorldLocation();
	CVector Distance = DistanceOrig;
	if (Distance.X < 0) Distance.X *= -1;
	if (Distance.Y < 0) Distance.Y *= -1;

	if (BoxOffset.X + PlayerOffset.X > Distance.X)
	{
		float scale = 1;
		if (DistanceOrig.X < 0) scale = -1;

		MoveRight(scale);
	}

	if (BoxOffset.Y + PlayerOffset.Y > Distance.Y)
	{
		float scale = 1;
		if (DistanceOrig.Y < 0) scale = -1;

		MoveForward(scale);
	}
}
