#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include <string>
#include <unordered_map>
#include <memory>

class EditorUIManager;

class EditorLayer
{
public:
	EditorLayer() {};
	~EditorLayer() {};

	void SetUUID(std::string id) { this->uuid = id; };
	std::string GetUUID() { return this->uuid; };

	virtual void Render() = 0;
	virtual void Construct() {};

protected:
	void RenderChildren();
	void DeleteChild(std::string id);

	template<typename Type>
	Type* AddChild()
	{
		std::shared_ptr<Type> NewLayer = std::make_shared<Type>();
		std::string id = EngineUtils::Generate();
		NewLayer->SetUUID(id);
		Children[id] = NewLayer;

		return NewLayer.get();
	};

protected:
	EditorUIManager* GetUIManager();

private:
	std::string uuid;
	std::unordered_map<std::string, std::shared_ptr<EditorLayer>> Children;
};

