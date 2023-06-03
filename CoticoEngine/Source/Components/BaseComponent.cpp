#include "BaseComponent.h"
#include "Core/CActor.h"

void BaseComponent::SetOwner(Ref<CActor> owner)
{
	this->Owner = owner;
	Owner->OnLocationChanged.AddListener(this, &BaseComponent::SetWorldLocation);
	SetWorldLocation(Owner->GetActorLocation());
}

