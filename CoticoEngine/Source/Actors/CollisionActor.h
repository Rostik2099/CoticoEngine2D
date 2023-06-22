#pragma once
#include "Core/CActor.h"
#include "Components/CollisionBoxComponent.h"

class CollisionActor : public CActor
{
public:
	CollisionActor()
	{
		Collision = SpawnComponent<CollisionBoxComponent>();
	};

	Ref<CollisionBoxComponent> GetCollision() { return this->Collision; };

private:
	Ref<CollisionBoxComponent> Collision;
};

