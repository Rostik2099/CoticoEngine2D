#pragma once
#include "EditorUI/EditorLayer.h"
#include "Types/SoftRef.h"

class CActor;
class OutlinerObject : public EditorLayer
{
public:
	OutlinerObject();

	virtual void Render() override;
	virtual void Construct() override;

	void SetActor(Ref<CActor> Actor)
	{
		ActorRef = Actor;
	};

private:
	Ref<CActor> ActorRef;
};

