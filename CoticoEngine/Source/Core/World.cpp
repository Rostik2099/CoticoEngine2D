#include "World.h"

#include "CActor.h"
#include "Components/CollisionBoxComponent.h"

void World::Tick(float DeltaTime)
{
	for (auto [id, actor] : Actors)
	{
		actor->Tick(DeltaTime);
	}

	for (auto [id, collision] : Collisions)
	{
		for (auto [id2, collision2] : Collisions)
		{
			if (id != id2 && collision->GetCollisionBox().getGlobalBounds().intersects(collision2->GetCollisionBox().getGlobalBounds()))
			{
				collision->OnCollide.Broadcast(collision2);
				collision2->OnCollide.Broadcast(collision);
			}
		}
	}

	DeleteActors();
}

void World::AddActorForDeletion(CActor* ActorToDelte)
{
	ActorsToDelete.push_back(ActorToDelte);
}

void World::AddCollision(std::shared_ptr<CollisionBoxComponent> Collision)
{
	Collisions[Collision->GetUUID()] = Collision;
}

void World::InitSpawnedActor(CActor* Actor, std::string ID)
{
	Actor->SetUUID(ID);
	Actor->SetCompsOwner();
	Actor->SetupInputs(InputManager::Get());
	Actor->BeginPlay();
}

void World::DeleteActors()
{
	for (auto actor : ActorsToDelete)
	{
		OnActorDeleted.Broadcast(actor);
		Actors.erase(actor->GetUUID());
	}
	ActorsToDelete.clear();
}

void World::ClearWorld()
{
	Actors.clear();
}