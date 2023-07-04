#pragma once
#include<unordered_map>
#include "BaseComponent.h"
#include "Events/CollisionEvent.h"

enum ECollisionType
{
	Block,
	Trigger,
};

enum ECollisionState 
{
	Static,
	Dynamic,
};

class CollisionBoxComponent : public BaseComponent
{
public:
	CollisionBoxComponent();

	~CollisionBoxComponent();
	void DestroyComponent() override;

	sf::RectangleShape GetCollisionBox() { return this->Collision; };
	bool GetCollisionVisibility() { return this->ShowCollision; };
	CVector GetCollisionBoxBounds() { return this->CollisionBounds; };
	ECollisionState GetCollisionState() { return this->State; };
	ECollisionType GetCollisionType() { return this->Type; };
	void SetCollisionState(ECollisionState NewState);
	void SetCollisionBounds(CVector NewBounds);
	void SetCollisionVisibility(bool NewVisibility) { this->ShowCollision = NewVisibility; };
	void SetCollisionType(ECollisionType NewType) { this->Type = NewType; };
	std::vector<CollisionBoxComponent*> GetOverlappingComponents() { return this->OverlappingComponents; };
	std::unordered_map<std::string, int> GetOverlappingIndices() { return this->OverlappingIndices; };
	void AddOverlapping(Ref<CollisionBoxComponent> Component);
	void RemoveOverlapping(Ref<CollisionBoxComponent> Component);

	void SetWorldLocation(CVector NewLoc) override;
	void SetRelativeLocation(CVector NewOffset) override;
	void ShowComponentProperties() override;

private:
	sf::RectangleShape Collision;
	CVector CollisionBounds;
	CVector BoxOffset;
	bool ShowCollision = true;
	ECollisionState State = Static;
	ECollisionType Type = Block;
	std::vector<CollisionBoxComponent*> OverlappingComponents;
	std::unordered_map<std::string, int> OverlappingIndices;

	//GUI
	int selectedState = 0;
	int selectedType = 0;

public:
	CollisionEvent OnCollide;
	CollisionEvent OnCollisionEnd;
};

