#include "LevelOutliner.h"
#include "TestActor.h"
#include "Core/World.h"

LevelOutliner::LevelOutliner() {}

void LevelOutliner::Render()
{
	ImGui::Begin("Level Outliner");

	if (ImGui::Button("Add Actor"))
	{
		World::Get()->SpawnActor<TestActor>();
	}

	ImGui::End();
}
