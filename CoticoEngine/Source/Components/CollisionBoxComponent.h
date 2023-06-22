#pragma once
#include "BaseComponent.h"
#include "Events/CollisionEvent.h"

class CollisionBoxComponent : public BaseComponent
{
public:
	CollisionBoxComponent();

	~CollisionBoxComponent();

	sf::RectangleShape GetCollisionBox() { return this->Collision; };
	bool GetCollisionVisibility() { return this->ShowCollision; };
	void SetCollisionBounds(CVector NewBounds);
	void SetCollisionVisibility(bool NewVisibility) { this->ShowCollision = NewVisibility; };

	void SetWorldLocation(CVector NewLoc) override;
	void SetRelativeLocation(CVector NewOffset) override;
	void ShowComponentProperties() override;

private:
	sf::RectangleShape Collision;
	CVector CollisionBounds;
	CVector BoxOffset;
	bool ShowCollision = true;

public:
	CollisionEvent OnCollide;
};

