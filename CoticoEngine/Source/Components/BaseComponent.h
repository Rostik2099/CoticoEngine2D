#pragma once
#include<string>
#include"Types/CVector.h"
#include"Types/SoftRef.h"

class BaseComponent
{
public:
	BaseComponent() {};
	~BaseComponent() {};

	virtual void BeginPlay() {};
	virtual void Tick(float DeltaTime) {};

	void SetUUID(std::string id) { this->uuid = id; };
	std::string GetUUID() { return this->uuid; };
	Ref<CActor> GetOwner() { return this->Owner; };
	void SetOwner(Ref<CActor> owner);
	virtual void OnOwnerLocChanged(CVector NewLoc);
	CVector GetWorldLocation() { return this->WorldLocation; };
	CVector GetLocalOffset() { return this->LocalOffset; };
	void SetWorldLocation(CVector NewLoc) { this->WorldLocation = NewLoc; };
	void SetLocalOffset(CVector NewOffset) { this->LocalOffset = NewOffset; };

private:
	std::string uuid;
	Ref<CActor> Owner;
	CVector LocalOffset;
	CVector WorldLocation;
};

