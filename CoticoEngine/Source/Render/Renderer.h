#pragma once
#include<map>
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
	sf::RenderTexture* GetRenderBuffer() { return &RenderBuffer; };

	void OnResize(int NewWidth, int NewHeight);
private:
	Renderer();
	void RemoveSprites();
	void GenerateRenderBuffer();
	
private:
	std::map<std::string, Ref<SpriteComponent>> SpriteComps;
	std::vector<std::string> SpritesToRemove;
	sf::RenderTexture RenderBuffer;

	int WindowHeight = 729, WindowWidth = 1280;
};

