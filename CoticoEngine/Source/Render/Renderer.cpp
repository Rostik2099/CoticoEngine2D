#include "Renderer.h"
#include <iostream>
#include "Core/CEngine.h"
#include "EditorUI/EditorUIManager.h"
#include "AppWindow/AppWindow.h"
#include "Components/SpriteComponent.h"
#include "Components/CollisionBoxComponent.h"
#include "Components/CameraComponent.h"

void Renderer::Render(sf::RenderWindow* CurrentWindow)
{
	CurrentWindow->clear(sf::Color::Black);
	RenderBuffer.setView(*CEngine::Get()->GetCurrentCamera()->GetCameraView());
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

	for (auto [id, collision] : Collisions)
	{
		if (collision)
		{
			if (collision->GetCollisionVisibility())
				RenderBuffer.draw(collision->GetCollisionBox());
		}
		else 
		{
			CollisionsToRemove.push_back(id);
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

void Renderer::AddCollisionBox(Ref<CollisionBoxComponent> collision)
{
	Collisions[collision->GetUUID()] = collision;
}

void Renderer::GetWindowSize(int& width, int& height)
{
	width = WindowWidth;
	height = WindowHeight;
}

void Renderer::OnResize(int NewWidth, int NewHeight)
{
	this->WindowWidth = NewWidth;
	this->WindowHeight = NewHeight;

	GenerateRenderBuffer();
	CEngine::Get()->GetCurrentCamera()->ResetView(sf::FloatRect(0, 0, WindowWidth, WindowHeight));
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

	for (auto collision : CollisionsToRemove)
	{
		Collisions.erase(collision);
	}
	CollisionsToRemove.clear();
}

void Renderer::GenerateRenderBuffer()
{
	RenderBuffer.create(WindowWidth, WindowHeight);
}
