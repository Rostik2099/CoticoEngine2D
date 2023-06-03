#include "BaseComponent.h"
#include "Core/CActor.h"

void BaseComponent::SetOwner(Ref<CActor> owner)
{
	this->Owner = owner;
	Owner->OnLocationChanged.AddListener(this, &BaseComponent::OnOwnerLocChanged);
}

void BaseComponent::OnOwnerLocChanged(CVector NewLoc)
{
	WorldLocation = NewLoc + LocalOffset;
}
