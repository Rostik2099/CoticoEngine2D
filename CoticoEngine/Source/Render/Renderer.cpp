#include "Renderer.h"
#include <iostream>
#include "Core/CEngine.h"
#include "EditorUI/EditorUIManager.h"
#include "AppWindow/AppWindow.h"
#include "Components/SpriteComponent.h"

void Renderer::Render(sf::RenderWindow* CurrentWindow)
{
	CurrentWindow->clear(sf::Color::Black);
	RenderBuffer.setView(*CEngine::Get()->GetCurrentCamera());
	RenderBuffer.clear();
	
	for (auto [id, sprite] : SpriteComps)
	{
		if (sprite)
		{
			RenderBuffer.draw(sprite->GetSprite());
		}
		else 
		{
			SpritesToRemove.push_back(id);
		}
	}

	RenderBuffer.display();

	EditorUIManager::Get()->Render();
	
	CurrentWindow->display();

	RemoveSprites();
}

void Renderer::AddSprite(Ref<SpriteComponent> sprite)
{
	SpriteComps[sprite->GetLayer() + sprite->GetUUID()] = sprite;
}

void Renderer::OnResize(int NewWidth, int NewHeight)
{
	this->WindowWidth = NewWidth;
	this->WindowHeight = NewHeight;

	GenerateRenderBuffer();
	CEngine::Get()->GetCurrentCamera()->reset(sf::FloatRect(0, 0, WindowWidth, WindowHeight));
}

Renderer::Renderer()
{
	GenerateRenderBuffer();
}

void Renderer::RemoveSprites()
{
	for (auto sprite : SpritesToRemove)
	{
		SpriteComps.erase(sprite);
	}
	SpritesToRemove.clear();
}

void Renderer::GenerateRenderBuffer()
{
	RenderBuffer.create(WindowWidth, WindowHeight);
}
