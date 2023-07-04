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
}

void CollisionBoxComponent::DestroyComponent()
{
	World::Get()->RemoveCollision(Ref<CollisionBoxComponent>(this));
}

void CollisionBoxComponent::SetCollisionState(ECollisionState NewState)
{
	this->State = NewState;
	selectedState = NewState;
	World::Get()->ChangeCollisionState(Ref<CollisionBoxComponent>(
		std::dynamic_pointer_cast<CollisionBoxComponent>(GetSelfPtr().lock())));
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
	OverlappingComponents.push_back(Component.GetRaw());
	OverlappingIndices[Component->GetUUID()] = 1;
	OnCollide.Broadcast(Component);
}

void CollisionBoxComponent::RemoveOverlapping(Ref<CollisionBoxComponent> Component)
{
	OnCollisionEnd.Broadcast(Component);
	OverlappingComponents.erase(remove(OverlappingComponents.begin(), OverlappingComponents.end(), Component.GetRaw()));
	OverlappingIndices.erase(Component->GetUUID());
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

	const char* types[] = { "Block", "Trigger" };
	if (ImGui::Combo("Collision Type", &selectedType, types, IM_ARRAYSIZE(types)))
	{
		if (selectedType == 0)
		{
			SetCollisionType(Block);
		}
		else SetCollisionType(Trigger);
	}
}
