#include "TestActor.h"
#include "Core/World.h"
#include "AppWindow/AppWindow.h"
#include "Core/CEngine.h"
#include "Utils/CoticoMath.h"
#include "Render/Renderer.h"
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
}

void TestActor::Tick(float dt)
{
	CActor::Tick(dt);

	//RotateToMouse();
}

void TestActor::MoveForward(float scale)
{
	UpDir = scale;
	LastLocation = GetActorLocation();
	CVector NewLoc = GetActorLocation() + CVector(0.f, scale * Speed * GetDeltaTime());
	SetActorLocation(NewLoc);
	CheckCollision();
	UpDir = 0;
}

void TestActor::MoveRight(float scale)
{
	RightDir = scale;
	LastLocation = GetActorLocation();
	CVector NewLoc = GetActorLocation() + CVector(scale * Speed * GetDeltaTime(), 0.f);
	SetActorLocation(NewLoc);
	CheckCollision();
	RightDir = 0;
}

void TestActor::CheckCollision()
{
	for (auto Overllaping : collision->GetOverlappingComponents())
	{
		CVector MinDistance = collision->GetCollisionBoxBounds() / 2.f + Overllaping->GetCollisionBoxBounds() / 2.f;
		CVector CurrentDistance = GetActorLocation() - Overllaping->GetWorldLocation();

		//Player Up and Down
		if (CurrentDistance.X > -MinDistance.X && 
			CurrentDistance.X < MinDistance.X)
		{
			//Up
			if (CurrentDistance.Y < 0 && CurrentDistance.Y * -1 < MinDistance.Y && UpDir == 1)
			{
				SetActorLocation(CVector(GetActorLocation().X, LastLocation.Y));
			}
			//Down
			if (CurrentDistance.Y > 0 && CurrentDistance.Y < MinDistance.Y && UpDir == -1)
			{
				SetActorLocation(CVector(GetActorLocation().X, LastLocation.Y));
			}
		}
		//Player Left and Right
		if (CurrentDistance.Y > -MinDistance.Y &&
			CurrentDistance.Y < MinDistance.Y)
		{
			//Left
			if (CurrentDistance.X < 0 && CurrentDistance.X * -1 < MinDistance.X && RightDir == 1)
			{
				SetActorLocation(CVector(LastLocation.X, GetActorLocation().Y));
			}
			//Right
			if (CurrentDistance.X > 0 && CurrentDistance.X < MinDistance.X && RightDir == -1)
			{
				SetActorLocation(CVector(LastLocation.X, GetActorLocation().Y));
			}
		}
	}
}

void TestActor::RotateToMouse()
{
	int windowWidth, windowHeight;
	Renderer::Get()->GetWindowSize(windowWidth, windowHeight);
	sf::Vector2i MousePixelCoord = sf::Mouse::getPosition(*CEngine::Get()->GetCurrentWindow()->GetSFWindow());
	CVector MouseWorldPos = CVector(MousePixelCoord.x, MousePixelCoord.y) - (CVector(windowWidth, windowHeight) / 2.f);

	std::cout << MouseWorldPos.X << " " << MouseWorldPos.Y << std::endl;
	//float angle = CoticoMath::FindLookAt(CVector(MouseWorldCoord) - GetActorLocation());
}
