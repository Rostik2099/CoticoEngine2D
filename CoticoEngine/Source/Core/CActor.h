#pragma once
#include<string>
#include<memory>
#include<unordered_map>
#include"Types/SoftRef.h"
#include"Utils/UUIDGenerator.h"

class World;
class BaseComponent;
class CActor
{
public:
	CActor();
	~CActor();

	virtual void BeginPlay() {};
	virtual void Tick(float DeltaTime);

	void SetUUID(std::string id) { this->uuid = id; };
	void Destroy();
	
	template<typename T>
	Ref<T> SpawnComponent() 
	{
		std::shared_ptr<T> SpawnedComp = std::make_shared<T>();
		std::string CompID = UUIDGenerator::Generate();
		Components[CompID] = SpawnedComp;
		Ref<T> CompRef = Ref<T>(SpawnedComp);
		InitComponent(SpawnedComp, CompID);
		return Ref<T>(SpawnedComp);
	};

private:
	void InitComponent(std::shared_ptr<BaseComponent> Component, std::string ID);

protected:
	World* GetWorld();

private:
	std::string uuid;
	std::unordered_map<std::string, std::shared_ptr<BaseComponent>> Components;
};

