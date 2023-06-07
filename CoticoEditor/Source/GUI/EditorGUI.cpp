#include "EditorGUI.h"
#include "LevelOutliner/LevelOutliner.h"

EditorGUI::EditorGUI()
{
	EditorUIManager::Get()->AddLayer<LevelOutliner>();
}
