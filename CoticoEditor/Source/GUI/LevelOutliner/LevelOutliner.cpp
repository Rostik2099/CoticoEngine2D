#include "LevelOutliner.h"
#include "TestActor.h"
#include "Core/World.h"
#include "Actors/SpriteActor.h"
#include "OutlinerObject.h"

LevelOutliner::LevelOutliner() {}

void LevelOutliner::Render()
{
	ImGui::Begin("Level Outliner");

	if (ImGui::Button("Add Sprite"))
	{
		World::Get()->SpawnActor<SpriteActor>();
	}

	ImGui::SameLine();

	if (ImGui::Button("Spawn Player"))
	{
		World::Get()->SpawnActor<TestActor>();
	}

	RenderChildren();

	ImGui::End();
}

void LevelOutliner::Construct()
{
	World::Get()->OnActorSpawned.AddListener(this, &LevelOutliner::AddObject);
	World::Get()->OnActorDeleted.AddListener(this, &LevelOutliner::DeleteObject);
}

void LevelOutliner::AddObject(Ref<CActor> Actor)
{
	OutlinerObject* Object = AddChild<OutlinerObject>();
	Object->SetActor(Actor);
	ObjectsForActors[Actor->GetUUID()] = Object->GetUUID();
}

void LevelOutliner::DeleteObject(Ref<CActor> Actor)
{
	std::string IdToDelete = ObjectsForActors[Actor->GetUUID()];
	DeleteChild(IdToDelete);
}
