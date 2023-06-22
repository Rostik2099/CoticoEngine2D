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

	ImGui::Begin("Viewport");
	ImVec2 CurrentSize = ImGui::GetWindowSize();
	if (CurrentSize.x != WindowWidth || CurrentSize.y != WindowHeight)
	{
		WindowWidth = CurrentSize.x;
		WindowHeight = CurrentSize.y;

		Renderer::Get()->OnResize(WindowWidth, WindowHeight);
	}

	ImGui::Image(*Renderer::Get()->GetRenderBuffer(), sf::Vector2f(WindowWidth, WindowHeight));
	ImGui::End();
}
