#include "OutlinerObject.h"
#include "GUI/EditorGUI.h"
#include "Core/CActor.h"

OutlinerObject::OutlinerObject() {}

void OutlinerObject::Render()
{
	if (ImGui::Button(ActorRef->GetUUID().c_str()))
	{
		EditorGUI::Get()->SetSelectedActor(ActorRef);
	}
}

void OutlinerObject::Construct()
{
}
