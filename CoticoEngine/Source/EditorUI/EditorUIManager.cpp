#include "EditorUIManager.h"
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

EditorUIManager::EditorUIManager()
{
	CurrentWindow = CEngine::Get()->GetCurrentWindow();
	ImGui::SFML::Init(*CurrentWindow->GetSFWindow());
}
