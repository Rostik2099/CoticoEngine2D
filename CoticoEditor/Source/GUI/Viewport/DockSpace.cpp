#include "DockSpace.h"

DockSpace::DockSpace()
{
}

void DockSpace::Render()
{
	ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
}