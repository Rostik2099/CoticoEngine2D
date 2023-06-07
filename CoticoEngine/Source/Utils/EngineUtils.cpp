#include "EngineUtils.h"
#include "Core/World.h"
#include "Components/BaseComponent.h"
#include "Core/CActor.h"
#include "EditorUI/EditorUIManager.h"
#include "EditorUI/EditorLayer.h"

std::shared_ptr<CActor> EngineUtils::GetActorByID(std::string id)
{
	return World::Get()->FindActorWithID(id);
}

std::shared_ptr<BaseComponent> EngineUtils::GetComponentByID(BaseComponent* comp)
{
	return comp->GetOwner()->GetComponentWithID(comp->GetUUID());
}

std::shared_ptr<EditorLayer> EngineUtils::GetEditorLayerByID(EditorLayer* layer)
{
	return EditorUIManager::Get()->GetLayerWithID(layer->GetUUID());
}
