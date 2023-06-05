#include "Renderer.h"
#include <iostream>
#include "Core/CEngine.h"
#include "EditorUI/EditorUIManager.h"
#include "AppWindow/AppWindow.h"
#include "Components/SpriteComponent.h"

void Renderer::Render(sf::RenderWindow* CurrentWindow)
{
	CurrentWindow->setView(*CEngine::Get()->GetCurrentCamera());
	CurrentWindow->clear(sf::Color::Black);
	
	for (auto [id, sprite] : SpriteComps)
	{
		if (sprite)
		{
			CurrentWindow->draw(sprite->GetSprite());
		}
		else 
		{
			SpritesToRemove.push_back(id);
		}
	}

	EditorUIManager::Get()->Render();
	
	CurrentWindow->display();

	RemoveSprites();
}

void Renderer::AddSprite(Ref<SpriteComponent> sprite)
{
	SpriteComps[sprite->GetLayer() + sprite->GetUUID()] = sprite;
}

void Renderer::RemoveSprites()
{
	for (auto sprite : SpritesToRemove)
	{
		SpriteComps.erase(sprite);
	}
	SpritesToRemove.clear();
}
