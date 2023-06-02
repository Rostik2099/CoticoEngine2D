#include "World.h"

#include "CActor.h"

void World::Tick(float DeltaTime)
{
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

void World::InitSpawnedActor(CActor* Actor, std::string ID)
{
	Actor->SetUUID(ID);
	Actor->SetupInputs(InputManager::Get());
	Actor->BeginPlay();
}

void World::DeleteActors()
{
	for (auto actor : ActorsToDelete)
	{
		Actors.erase(actor->GetUUID());
	}
	ActorsToDelete.clear();
}
