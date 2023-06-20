#pragma once
#include "EditorUI/EditorLayer.h"
#include "Types/SoftRef.h"
#include <unordered_map>

class CActor;
class LevelOutliner : public EditorLayer
{
public:
	LevelOutliner();

	virtual void Render() override;
	virtual void Construct() override;

private:
	void AddObject(Ref<CActor> Actor);
	void DeleteObject(Ref<CActor> Actor);

	std::unordered_map<std::string, std::string> ObjectsForActors;
};

