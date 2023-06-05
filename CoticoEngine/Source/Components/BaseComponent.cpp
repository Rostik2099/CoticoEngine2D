#include "BaseComponent.h"
#include "Core/CActor.h"

void BaseComponent::SetOwner(Ref<CActor> owner)
{
	this->Owner = owner;
	Owner->OnLocationChanged.AddListener(this, &BaseComponent::OnOwnerLocChanged);
	SetWorldLocation(Owner->GetActorLocation());
}

CVector BaseComponent::GetWorldLocation()
{
	return GetOwner()->GetActorLocation() + this->Offset;
}

void BaseComponent::SetWorldLocation(CVector NewLoc)
{
	this->Offset = NewLoc - GetOwner()->GetActorLocation();
}

void BaseComponent::OnOwnerLocChanged(CVector NewLoc)
{
	SetWorldLocation(NewLoc + Offset);
}
