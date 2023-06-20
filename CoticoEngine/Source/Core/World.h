#pragma once
#include <unordered_map>
#include <iostream>
#include <memory>
#include "Types/SoftRef.h"
#include "Events/ActorEvent.h"

#include"Utils/EngineUtils.h"

class CActor;

class World
{
public:
	static World* Get()
	{
		static World world;
		return &world;
	};

	template<typename Type>
	Ref<Type> SpawnActor()
	{
		std::shared_ptr<Type> NewActor = std::make_shared<Type>();
		std::string ActorID = EngineUtils::Generate();
		Actors[ActorID] = NewActor;
		InitSpawnedActor(NewActor.get(), ActorID);
		OnActorSpawned.Broadcast(Ref<CActor>(NewActor));
		return Ref<Type>(NewActor);
	};

	void Tick(float DeltaTime);

	void AddActorForDeletion(CActor* ActorToDelte);
	std::shared_ptr<CActor> FindActorWithID(std::string id) { return Actors[id]; };

private:
	void InitSpawnedActor(CActor* Actor, std::string ID);
	void DeleteActors();
	World() {};

private:
	std::unordered_map<std::string, std::shared_ptr<CActor>> Actors;
	std::vector<CActor*> ActorsToDelete;

public:
	ActorEvent OnActorSpawned;
	ActorEvent OnActorDeleted;
};

