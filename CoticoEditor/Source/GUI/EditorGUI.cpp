#include "EditorGUI.h"
#include "LevelOutliner/LevelOutliner.h"
#include "Properties/Properties.h"

void EditorGUI::SetSelectedActor(Ref<CActor> actor)
{
	this->SelectedActor = actor;
	OnActorSelected.Broadcast(SelectedActor);
}

void EditorGUI::DeselectActor()
{
	OnActorDeselected.Broadcast(SelectedActor);
	SelectedActor = Ref<CActor>();
}

EditorGUI::EditorGUI()
{
	EditorUIManager::Get()->AddLayer<LevelOutliner>();
	EditorUIManager::Get()->AddLayer<Properties>();
}
