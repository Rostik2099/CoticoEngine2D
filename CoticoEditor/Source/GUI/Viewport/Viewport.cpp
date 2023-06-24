#include "Viewport.h"
#include "Render/Renderer.h"

Viewport::Viewport()
{
}

void Viewport::Construct()
{
}

void Viewport::Render()
{
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
	ImGui::Begin("Viewport", NULL, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoTitleBar);
	ImVec2 CurrentSize = ImGui::GetWindowSize();
	if (CurrentSize.x != WindowWidth || CurrentSize.y != WindowHeight)
	{
		WindowWidth = CurrentSize.x;
		WindowHeight = CurrentSize.y;

		Renderer::Get()->OnResize(WindowWidth, WindowHeight);
	}

	ImGui::Image(*Renderer::Get()->GetRenderBuffer(), ImGui::GetWindowSize());
	ImGui::End();
	ImGui::PopStyleVar();
}
