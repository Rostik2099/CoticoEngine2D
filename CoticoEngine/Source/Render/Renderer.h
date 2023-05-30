#pragma once
#include<unordered_map>
#include<memory>

#include "SFML/Graphics.hpp"
#include "Types/SoftRef.h"

class SpriteComponent;
class Renderer
{
public:
	static Renderer* Get() 
	{
		static Renderer renderer;
		return &renderer;
	};

	void Render(sf::RenderWindow* CurrentWindow);
	void AddSprite(Ref<SpriteComponent> sprite);

private:
	Renderer() {};
	
private:
	std::unordered_map<std::string, Ref<SpriteComponent>> SpriteComps;
};

