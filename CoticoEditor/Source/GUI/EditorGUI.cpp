#include "EditorGUI.h"
#include "LevelOutliner/LevelOutliner.h"
#include "Properties/Properties.h"
#include "Viewport/Viewport.h"
#include "Viewport/DockSpace.h"

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
	EditorUIManager::Get()->CreateDockSpace<DockSpace>();
	EditorUIManager::Get()->AddLayer<Viewport>();
	EditorUIManager::Get()->AddLayer<LevelOutliner>();
	EditorUIManager::Get()->AddLayer<Properties>();
}
