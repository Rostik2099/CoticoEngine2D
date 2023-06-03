#include "SpriteComponent.h"
#include <iostream>

SpriteComponent::SpriteComponent() 
{
	Sprite = sf::Sprite(Texture, sf::IntRect(0, 0, 64, 64));
	Sprite.setColor(sf::Color::White);
}

SpriteComponent::~SpriteComponent() {}

void SpriteComponent::SetTexture(std::string path)
{
	if (!Texture.loadFromFile(path)) std::cout << "Failed to load texture: path";
	Sprite.setTexture(Texture, true);
}

void SpriteComponent::SetScale(CVector NewScale)
{
	Sprite.setScale(NewScale.ToSFVector());
}

void SpriteComponent::OnOwnerLocChanged(CVector NewLoc)
{
	CVector offset = NewLoc + ((GetWorldLocation() + GetLocalOffset()) * -1);
	Sprite.move(offset.ToSFVector());
	BaseComponent::OnOwnerLocChanged(NewLoc);
}
