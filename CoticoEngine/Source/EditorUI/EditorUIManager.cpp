#include "EditorUIManager.h"
#include "EditorLayer.h"
#include "Core/CEngine.h"
#include "AppWindow/AppWindow.h"

void EditorUIManager::ProcessEvents(sf::Event event)
{
	ImGui::SFML::ProcessEvent(event);
}

void EditorUIManager::Update()
{
	ImGui::SFML::Update(*CurrentWindow->GetSFWindow(), CEngine::Get()->GetDeltaClock());
}

void EditorUIManager::Render()
{
	for (auto [id, layer] : Layers)
	{
		layer->Render();
	}

	ImGui::SFML::Render(*CurrentWindow->GetSFWindow());
}

void EditorUIManager::ShutDown()
{
	ImGui::SFML::Shutdown();
}

EditorUIManager::~EditorUIManager()
{
	ShutDown();
}

void EditorUIManager::InitLayer(EditorLayer* layer, std::string id)
{
	layer->SetUUID(id);
}

EditorUIManager::EditorUIManager()
{
	CurrentWindow = CEngine::Get()->GetCurrentWindow();
	ImGui::SFML::Init(*CurrentWindow->GetSFWindow());
}
