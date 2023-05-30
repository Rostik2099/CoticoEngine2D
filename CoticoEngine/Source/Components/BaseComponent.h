#pragma once
#include<string>
#include"Types/CVector.h"

class BaseComponent
{
public:
	BaseComponent() {};
	~BaseComponent() {};

	virtual void BeginPlay() {};
	virtual void Tick(float DeltaTime) {};

	void SetUUID(std::string id) { this->uuid = id; };
	std::string GetUUID() { return this->uuid; };

private:
	std::string uuid;
};

