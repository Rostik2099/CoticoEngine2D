#include "EngineUtils.h"
#include "Core/World.h"

std::shared_ptr<CActor> EngineUtils::GetActorByID(std::string id)
{
	return World::Get()->FindActorWithID(id);
}
