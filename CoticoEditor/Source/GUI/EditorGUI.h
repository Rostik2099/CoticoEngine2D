#pragma once
#include "EditorUI/EditorUIManager.h"
#include "Types/SoftRef.h"
#include "Events/ActorEvent.h"

class CActor;
class EditorGUI
{
public:
	static EditorGUI* Get()
	{
		static EditorGUI gui;
		return &gui;
	};

	void SetSelectedActor(Ref<CActor> actor);
	void DeselectActor();
	Ref<CActor> GetSelectedActor() { return this->SelectedActor;  };

private:
	EditorGUI();
	Ref<CActor> SelectedActor;

public:
	ActorEvent OnActorSelected;
	ActorEvent OnActorDeselected;
};

