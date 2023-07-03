#pragma once
#include "BaseComponent.h"
#include "Events/CollisionEvent.h"

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

	sf::RectangleShape GetCollisionBox() { return this->Collision; };
	bool GetCollisionVisibility() { return this->ShowCollision; };
	CVector GetCollisionBoxBounds() { return this->CollisionBounds; };
	ECollisionState GetCollisionState() { return this->State; };
	void SetCollisionState(ECollisionState NewState) { this->State = NewState; };
	void SetCollisionBounds(CVector NewBounds);
	void SetCollisionVisibility(bool NewVisibility) { this->ShowCollision = NewVisibility; };
	std::vector<Ref<CollisionBoxComponent>> GetOverlappingComponents() { return this->OverlappingComponents; };
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
	ECollisionState State;
	std::vector<Ref<CollisionBoxComponent>> OverlappingComponents;

	//GUI
	int selectedState = 0;

public:
	CollisionEvent OnCollide;
	CollisionEvent OnCollisionEnd;
};

