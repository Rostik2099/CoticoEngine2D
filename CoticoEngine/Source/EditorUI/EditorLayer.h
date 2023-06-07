#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include <string>

class EditorUIManager;

class EditorLayer
{
public:
	EditorLayer() {};

	void SetUUID(std::string id) { this->uuid = id; };
	std::string GetUUID() { return this->uuid; };

	virtual void Render() = 0;

protected:
	EditorUIManager* GetUIManager();

private:
	std::string uuid;
};

