#include "Properties.h"
#include "Core/CActor.h"
#include "GUI/EditorGUI.h"
#include "Components/BaseComponent.h"

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
	std::string id = "Actor: " + SelectedActor->GetUUID();
	ImGui::Text(id.c_str());

	float Location[2];
	Location[0] = SelectedActor->GetActorLocation().X;
	Location[1] = SelectedActor->GetActorLocation().Y;

	if (ImGui::DragFloat2("Location", Location))
	{
		SelectedActor->SetActorLocation(CVector(Location[0], Location[1]));
	}
}

void Properties::ShowComponentsProperties()
{
	for (auto [id, comp] : SelectedActor->GetComponentsList())
	{
		std::string CompID = "Component: " + comp->GetUUID();
		ImGui::Text(CompID.c_str());
		comp->ShowComponentProperties();
	}
}
