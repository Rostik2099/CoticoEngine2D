#include "Renderer.h"
#include "AppWindow/AppWindow.h"
#include "Components/SpriteComponent.h"

void Renderer::Render(sf::RenderWindow* CurrentWindow)
{
	CurrentWindow->clear(sf::Color::Black);
	
	for (auto [id, sprite] : SpriteComps)
	{
		if (sprite)
		{
			CurrentWindow->draw(sprite->GetSprite());
		}
	}
	
	CurrentWindow->display();
}

void Renderer::AddSprite(Ref<SpriteComponent> sprite)
{
	SpriteComps[sprite->GetUUID()] = sprite;
}
