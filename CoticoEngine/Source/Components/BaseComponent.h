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
	CVector GetWorldLocation();
	CVector GetRelativeLocation() { return this->Offset; };
	virtual void SetWorldLocation(CVector NewLoc);
	virtual void SetRelativeLocation(CVector NewOffset) { this->Offset = NewOffset; };
	void OnOwnerLocChanged(CVector NewLoc);

private:
	std::string uuid;
	Ref<CActor> Owner;
	CVector Offset;
};

