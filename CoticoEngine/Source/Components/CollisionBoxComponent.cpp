#include "CollisionBoxComponent.h"
#include "Core/CActor.h"
#include "Core/World.h"

CollisionBoxComponent::CollisionBoxComponent()
{
	Collision.setOutlineColor(sf::Color::Green);
	Collision.setFillColor(sf::Color(0, 0, 0, 0));
	Collision.setOutlineThickness(2.f);
	SetCollisionBounds(CVector(64, 64));
}

CollisionBoxComponent::~CollisionBoxComponent()
{
	World::Get()->RemoveCollision(GetUUID());
}

void CollisionBoxComponent::SetCollisionBounds(CVector NewBounds)
{
	CollisionBounds = NewBounds;
	Collision.setSize(CollisionBounds.ToSFVector());
	BoxOffset = CVector(CollisionBounds.X / 2, CollisionBounds.Y / 2);
	Collision.setOrigin(BoxOffset.ToSFVector());
}



void CollisionBoxComponent::AddOverlapping(Ref<CollisionBoxComponent> Component)
{
	OverlappingComponents.push_back(Component);
	OnCollide.Broadcast(Component);
}

void CollisionBoxComponent::RemoveOverlapping(Ref<CollisionBoxComponent> Component)
{
	OnCollisionEnd.Broadcast(Component);
	auto iterator = std::find(OverlappingComponents.begin(), OverlappingComponents.end(), Component);
	if (iterator != OverlappingComponents.end())
		OverlappingComponents.erase(iterator);
}

void CollisionBoxComponent::SetWorldLocation(CVector NewLoc)
{
	Collision.setPosition((NewLoc).ToSFVector());
	BaseComponent::SetWorldLocation(NewLoc);
}

void CollisionBoxComponent::SetRelativeLocation(CVector NewOffset)
{
	if (GetOwner())
		Collision.setPosition((GetOwner()->GetActorLocation() + NewOffset).ToSFVector());

	BaseComponent::SetRelativeLocation(NewOffset);
}

void CollisionBoxComponent::ShowComponentProperties()
{
	float Bounds[2];
	Bounds[0] = CollisionBounds.X;
	Bounds[1] = CollisionBounds.Y;
	if (ImGui::DragFloat2("Collision Bounds", Bounds))
	{
		SetCollisionBounds(CVector(Bounds[0], Bounds[1]));
	}

	ImGui::Checkbox("Show Collision", &ShowCollision);
	
	const char* items[] = {"Static", "Dynamic"};
	if (ImGui::Combo("Collision State", &selectedState, items, IM_ARRAYSIZE(items)))
	{
		if (selectedState == 0)
		{
			SetCollisionState(Static);
		}
		else SetCollisionState(Dynamic);
	}
}
