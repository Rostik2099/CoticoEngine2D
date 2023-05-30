#include "World.h"

#include "CActor.h"

void World::Tick(float DeltaTime)
{
	for (auto [id, actor] : Actors)
	{
		actor->Tick(DeltaTime);
	}
}

void World::InitSpawnedActor(CActor* Actor, std::string ID)
{
	Actor->SetUUID(ID);
	Actor->BeginPlay();
}
