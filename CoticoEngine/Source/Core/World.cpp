#include "World.h"
#include "CActor.h"
#include "Components/CollisionBoxComponent.h"

void World::Tick(float DeltaTime)
{
	for (auto colliderDyn : DynamicColliders)
	{
		for (auto colliderStat : StaticColliders)
		{
			if (colliderDyn->GetCollisionBox().getGlobalBounds().intersects(colliderStat->GetCollisionBox().getGlobalBounds()))
			{
				if(colliderDyn->GetOverlappingIndices().count(colliderStat->GetUUID()) == 0)
				{
					colliderDyn->AddOverlapping(colliderStat);
					colliderStat->AddOverlapping(colliderDyn);
				}
			}
			else 
			{
				if (colliderDyn->GetOverlappingIndices().count(colliderStat->GetUUID()) != 0)
				{
					colliderDyn->RemoveOverlapping(colliderStat);
					colliderStat->RemoveOverlapping(colliderDyn);
				}
			}
		}
		for (auto collider2 : DynamicColliders)
		{
			if (collider2 != colliderDyn)
			{
				if (colliderDyn->GetCollisionBox().getGlobalBounds().intersects(collider2->GetCollisionBox().getGlobalBounds()))
				{
					if (colliderDyn->GetOverlappingIndices().count(collider2->GetUUID()) == 0)
					{
						colliderDyn->AddOverlapping(collider2);
						collider2->AddOverlapping(colliderDyn);
					}
				}
				else
				{
					if (colliderDyn->GetOverlappingIndices().count(collider2->GetUUID()) != 0)
					{
						colliderDyn->RemoveOverlapping(collider2);
						collider2->RemoveOverlapping(colliderDyn);
					}
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
	if (Collision->GetCollisionState() == Dynamic)
	{
		DynamicColliders.push_back(Collision);
	}
	if (Collision->GetCollisionState() == Static)
	{
		StaticColliders.push_back(Collision);
	}
}

void World::RemoveCollision(Ref<CollisionBoxComponent> Collision)
{
	if (Collision->GetCollisionState() == Dynamic)
	{
		DynamicColliders.erase(remove(DynamicColliders.begin(), DynamicColliders.end(), Collision));
	}
	else
	{
		StaticColliders.erase(remove(StaticColliders.begin(), StaticColliders.end(), Collision));
	}
}

void World::ChangeCollisionState(Ref<CollisionBoxComponent> Component)
{
	if (Component->GetCollisionState() == Dynamic)
	{
		StaticColliders.erase(remove(StaticColliders.begin(), StaticColliders.end(), Component));
		DynamicColliders.push_back(Component);
	}
	else 
	{
		DynamicColliders.erase(remove(DynamicColliders.begin(), DynamicColliders.end(), Component));
		StaticColliders.push_back(Component);
	}
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
		actor->DestroyComponents();
		Actors.erase(actor->GetUUID());
	}
	ActorsToDelete.clear();
}

void World::ClearWorld()
{
	Actors.clear();
}