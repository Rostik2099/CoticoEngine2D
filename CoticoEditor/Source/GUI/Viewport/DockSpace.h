#pragma once
#include "EditorUI/EditorLayer.h"

class DockSpace : public EditorLayer
{
public:
	DockSpace();

	void Render() override;
};

