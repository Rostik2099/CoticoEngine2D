#include "Properties.h"
#include "Core/CActor.h"
#include "GUI/EditorGUI.h"

Properties::Properties()
{
}

void Properties::Render()
{
	ImGui::Begin("Properties");

	if (SelectedActor)
	{
		ShowActorProperties();

		ShowComponentsProperties();

		if (ImGui::Button("Delete"))
		{
			SelectedActor->Destroy();
			OnActorDeselected(SelectedActor);
		}
	}
	else
	{
		ImGui::Text("No actor selected");
	}

	ImGui::End();
}

void Properties::Construct()
{
	EditorGUI::Get()->OnActorSelected.AddListener(this, &Properties::OnActorSelected);
	EditorGUI::Get()->OnActorDeselected.AddListener(this, &Properties::OnActorDeselected);
}

void Properties::OnActorSelected(Ref<CActor> actor)
{
	SelectedActor = actor;
}

void Properties::OnActorDeselected(Ref<CActor> actor)
{
	SelectedActor = Ref<CActor>();
}

void Properties::ShowActorProperties()
{
	std::string id = "UUID: " + SelectedActor->GetUUID();
	ImGui::Text(id.c_str());
}

void Properties::ShowComponentsProperties()
{
}
