#pragma once
#include<map>
#include<unordered_map>
#include<memory>

#include "SFML/Graphics.hpp"
#include "Types/SoftRef.h"

class SpriteComponent;
class CollisionBoxComponent;
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
	void AddCollisionBox(Ref<CollisionBoxComponent> collision);
	sf::RenderTexture* GetRenderBuffer() { return &RenderBuffer; };
	void GetWindowSize(int& width, int& height);

	void OnResize(int NewWidth, int NewHeight);
private:
	Renderer();
	void RemoveSprites();
	void GenerateRenderBuffer();
	
private:
	std::map<std::string, Ref<SpriteComponent>> SpriteComps;
	std::unordered_map<std::string, Ref<CollisionBoxComponent>> Collisions;
	std::vector<std::string> SpritesToRemove;
	std::vector<std::string> CollisionsToRemove;
	sf::RenderTexture RenderBuffer;

	int WindowHeight = 729, WindowWidth = 1280;
};

