#pragma once
#include<string>
#include<memory>
#include"UUID/uuid.h"

class CActor;
class BaseComponent;
class EditorLayer;

class EngineUtils
{
public:
	static std::string Generate() 
	{
		UUIDv4::UUIDGenerator<std::mt19937_64> uuidGenerator;
		UUIDv4::UUID uuid = uuidGenerator.getUUID();
		return uuid.str();
	};

	static std::shared_ptr<CActor> GetActorByID(std::string id);
	static std::shared_ptr<BaseComponent> GetComponentByID(BaseComponent* comp);
	static std::shared_ptr<EditorLayer> GetEditorLayerByID(EditorLayer* layer);
};