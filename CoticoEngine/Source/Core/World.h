#pragma once
#include <unordered_map>
#include <iostream>
#include <memory>
#include "Types/SoftRef.h"

#include"Utils/UUIDGenerator.h"

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
		std::string ActorID = UUIDGenerator::Generate();
		Actors[ActorID] = NewActor;
		InitSpawnedActor(NewActor.get(), ActorID);
		return Ref<Type>(NewActor);
	};

	void Tick(float DeltaTime);

	void AddActorForDeletion(CActor* ActorToDelte);

private:
	void InitSpawnedActor(CActor* Actor, std::string ID);
	void DeleteActors();

private:
	World() {};

	std::unordered_map<std::string, std::shared_ptr<CActor>> Actors;
	std::vector<CActor*> ActorsToDelete;
};

