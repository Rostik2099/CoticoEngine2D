#pragma once
#include "EditorUI/EditorLayer.h"

class Viewport : public EditorLayer
{
public:
	Viewport();

	void Construct() override;
	void Render() override;

private:
	float WindowHeight;
	float WindowWidth;
};

