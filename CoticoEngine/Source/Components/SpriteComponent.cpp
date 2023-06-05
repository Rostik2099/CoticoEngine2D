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
	ImageOffset = ImageOffset * NewScale;
}

void SpriteComponent::SetWorldLocation(CVector NewLoc)
{
	Sprite.setPosition((NewLoc - ImageOffset).ToSFVector());
	BaseComponent::SetWorldLocation(NewLoc);
}

void SpriteComponent::SetRelativeLocation(CVector NewOffset)
{
	Sprite.setPosition((GetOwner()->GetActorLocation() + NewOffset - ImageOffset).ToSFVector());
	BaseComponent::SetRelativeLocation(NewOffset);
}
