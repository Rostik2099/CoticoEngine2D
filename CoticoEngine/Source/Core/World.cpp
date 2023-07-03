#include "World.h"
#include<vector>
#include "CActor.h"
#include "Components/CollisionBoxComponent.h"

void World::Tick(float DeltaTime)
{
	for (auto [id, collision] : Collisions)
	{
		for (auto [id2, collision2] : Collisions)
		{
			if (id != id2 && collision.lock()->GetCollisionBox().getGlobalBounds().intersects(collision2.lock()->GetCollisionBox().getGlobalBounds()))
			{
				if (std::find(collision.lock()->GetOverlappingComponents().begin(), collision.lock()->GetOverlappingComponents().end(), Ref<CollisionBoxComponent>(collision2.lock())) == collision.lock()->GetOverlappingComponents().end())
				{
					collision.lock()->AddOverlapping(Ref<CollisionBoxComponent>(collision2.lock()));
					collision2.lock()->AddOverlapping(Ref<CollisionBoxComponent>(collision.lock()));
				}
			}
			else 
			{
				if (id != id2 && std::find(collision.lock()->GetOverlappingComponents().begin(), collision.lock()->GetOverlappingComponents().end(), Ref<CollisionBoxComponent>(collision2.lock())) != collision.lock()->GetOverlappingComponents().end())
				{
					collision.lock()->RemoveOverlapping(Ref<CollisionBoxComponent>(collision2.lock()));
					collision2.lock()->RemoveOverlapping(Ref<CollisionBoxComponent>(collision.lock()));
				}
			}
		}
	}

	for (auto [id, actor] : Actors)
	{
		actor->Tick(DeltaTime);
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