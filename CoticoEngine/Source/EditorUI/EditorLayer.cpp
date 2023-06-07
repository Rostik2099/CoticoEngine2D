#include "EditorLayer.h"
#include "EditorUIManager.h"

EditorUIManager* EditorLayer::GetUIManager()
{
    return EditorUIManager::Get();
}
