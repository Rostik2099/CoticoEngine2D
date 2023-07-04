#pragma once
#include <unordered_map>
#include <iostream>
#include <vector>
#include <memory>
#include "Types/SoftRef.h"
#include "Events/ActorEvent.h"

#include"Utils/EngineUtils.h"

class CActor;
class CollisionBoxComponent;

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
	void AddCollision(std::shared_ptr<CollisionBoxComponent> Collision);
	void RemoveCollision(Ref<CollisionBoxComponent> Collision);
	void ChangeCollisionState(Ref<CollisionBoxComponent> Component);
	std::shared_ptr<CActor> FindActorWithID(std::string id) { return Actors[id]; };

private:
	void InitSpawnedActor(CActor* Actor, std::string ID);
	void DeleteActors();
	World() {};
	~World() { ClearWorld(); };
	void ClearWorld();

private:
	std::unordered_map<std::string, std::shared_ptr<CActor>> Actors;
	std::vector<Ref<CollisionBoxComponent>> StaticColliders;
	std::vector<Ref<CollisionBoxComponent>> DynamicColliders;
	std::vector<CActor*> ActorsToDelete;

public:
	ActorEvent OnActorSpawned;
	ActorEvent OnActorDeleted;
};

