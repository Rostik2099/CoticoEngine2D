#include "EditorLayer.h"
#include "EditorUIManager.h"

void EditorLayer::RenderChildren()
{
    for (auto [id, child] : Children)
    {
        child->Render();
    }
}

void EditorLayer::DeleteChild(std::string id)
{
    Children.erase(id);
}

EditorUIManager* EditorLayer::GetUIManager()
{
    return EditorUIManager::Get();
}
