#pragma once

#include "imgui.h"
#include "imgui-SFML.h"
#include "Utils/EngineUtils.h"
#include "Types/SoftRef.h"
#include <unordered_map>
#include <memory>
#include <string>

class AppWindow;
class EditorLayer;

class EditorUIManager
{
public:
	static EditorUIManager* Get()
	{
		static EditorUIManager manager;
		return &manager;
	};

	template<typename T>
	Ref<T> AddLayer() 
	{
		std::shared_ptr<T> NewLayer = std::make_shared<T>();
		std::string LayerID = EngineUtils::Generate();
		Layers[LayerID] = NewLayer;
		InitLayer(NewLayer.get(), LayerID);
		return Ref<T>(NewLayer.get());
	};

	void ProcessEvents(sf::Event event);
	void Update();
	void Render();
	void ShutDown();

	std::shared_ptr<EditorLayer> GetLayerWithID(std::string id) { return this->Layers[id]; };

	~EditorUIManager();

private:
	EditorUIManager();
	void InitLayer(EditorLayer* layer, std::string id);

private:
	AppWindow* CurrentWindow;
	std::unordered_map<std::string, std::shared_ptr<EditorLayer>> Layers;
};

