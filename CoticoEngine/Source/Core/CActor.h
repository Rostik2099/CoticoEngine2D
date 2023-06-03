#pragma once
#include<string>
#include<memory>
#include<unordered_map>
#include"Types/SoftRef.h"
#include"Types/CVector.h"
#include"Utils/EngineUtils.h"
#include"Input/InputManager.h"
#include"Events/VectorEvent.h"

class World;
class BaseComponent;

class CActor
{
public:
	CActor();
	~CActor();

	virtual void BeginPlay() {};
	virtual void Tick(float DeltaTime);
	virtual void SetupInputs(InputManager* inputManager) {};

	std::string GetUUID() { return this->uuid; };
	void SetUUID(std::string id) { this->uuid = id; };
	void Destroy();
	CVector GetActorLocation() { return this->Location; };
	void SetActorLocation(CVector NewLoc);
	std::shared_ptr<BaseComponent> GetComponentWithID(std::string id);
	void SetCompsOwner();
	
	template<typename T>
	Ref<T> SpawnComponent() 
	{
		std::shared_ptr<T> SpawnedComp = std::make_shared<T>();
		std::string CompID = EngineUtils::Generate();
		Components[CompID] = SpawnedComp;
		Ref<T> CompRef = Ref<T>(SpawnedComp);
		InitComponent(SpawnedComp, CompID);
		return Ref<T>(SpawnedComp);
	};

private:
	void InitComponent(std::shared_ptr<BaseComponent> Component, std::string ID);

protected:
	World* GetWorld();
	float GetDeltaTime() { return this->dt; };

private:
	std::string uuid;
	std::unordered_map<std::string, std::shared_ptr<BaseComponent>> Components;
	float dt;
	CVector Location;

public:
	VectorEvent OnLocationChanged;
};

