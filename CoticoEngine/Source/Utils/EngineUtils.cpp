#include "EngineUtils.h"
#include "Core/World.h"
#include "Components/BaseComponent.h"
#include "Core/CActor.h"

std::shared_ptr<CActor> EngineUtils::GetActorByID(std::string id)
{
	return World::Get()->FindActorWithID(id);
}

std::shared_ptr<BaseComponent> EngineUtils::GetComponentByID(BaseComponent* comp)
{
	return comp->GetOwner()->GetComponentWithID(comp->GetUUID());
}
