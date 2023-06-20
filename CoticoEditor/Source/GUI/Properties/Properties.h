#pragma once
#include "EditorUI/EditorLayer.h"
#include "Types/SoftRef.h"

class CActor;

class Properties : public EditorLayer
{
public:
	Properties();

	void Render() override;
	void Construct() override;

	void OnActorSelected(Ref<CActor> actor);
	void OnActorDeselected(Ref<CActor> actor);
private:
	void ShowActorProperties();
	void ShowComponentsProperties();

private:
	Ref<CActor> SelectedActor;
};

