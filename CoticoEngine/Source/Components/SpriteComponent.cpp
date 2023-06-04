#include "SpriteComponent.h"
#include "Core/CActor.h"
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

	ImageOffset = CVector(Sprite.getGlobalBounds().width / 2, Sprite.getGlobalBounds().height / 2);
}

void SpriteComponent::SetScale(CVector NewScale)
{
	Sprite.setScale(NewScale.ToSFVector());
}

void SpriteComponent::SetWorldLocation(CVector NewLoc)
{
	Sprite.setPosition((NewLoc - CVector(ImageOffset.X * Sprite.getScale().x, ImageOffset.Y * Sprite.getScale().y)).ToSFVector());
	BaseComponent::SetWorldLocation(NewLoc);
}
