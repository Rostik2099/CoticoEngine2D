#include "SpriteComponent.h"
#include <fstream>
#include "Core/CActor.h"
#include <iostream>

SpriteComponent::SpriteComponent() 
{
	Sprite = sf::Sprite(Texture, sf::IntRect(0, 0, 64, 64));
	ImageOffset = CVector(32, 32);
	Sprite.setOrigin(ImageOffset.ToSFVector());
	Sprite.setColor(sf::Color::White);
}

SpriteComponent::~SpriteComponent() {}

void SpriteComponent::SetTexture(std::string path)
{
	std::string str = "Content/" + path;
	if (!Texture.loadFromFile(str)) std::cout << "Failed to load texture: " << path << std::endl;
	Sprite.setTexture(Texture, true);

	ImageOffset = CVector(Sprite.getGlobalBounds().width / 2, Sprite.getGlobalBounds().height / 2);
	Sprite.setOrigin(ImageOffset.ToSFVector());
	TexturePath = path;
	SetRelativeLocation(GetRelativeLocation());

	std::strcpy(buffer, TexturePath.c_str());
}

void SpriteComponent::SetScale(CVector NewScale)
{
	Sprite.setScale(NewScale.ToSFVector());
	ImageOffset = ImageOffset * NewScale;
}

void SpriteComponent::SetWorldLocation(CVector NewLoc)
{
	Sprite.setPosition((NewLoc).ToSFVector());
	BaseComponent::SetWorldLocation(NewLoc);
}

void SpriteComponent::SetRelativeLocation(CVector NewOffset)
{
	if (GetOwner())
		Sprite.setPosition((GetOwner()->GetActorLocation() + NewOffset).ToSFVector());

	BaseComponent::SetRelativeLocation(NewOffset);
}

void SpriteComponent::ShowComponentProperties()
{
	if (ImGui::InputText("Texture path", buffer, sizeof(buffer), ImGuiInputTextFlags_EnterReturnsTrue))
	{
		std::string path = buffer;
		std::fstream inf("Content/" + path);

		if (inf.good())
		{
			inf.close();
			SetTexture(buffer);
		}
		else
		{
			std::cout << "File: " << path << " Not found" << std::endl;
			std::strcpy(buffer, TexturePath.c_str());
		}
	}
}

void SpriteComponent::SetRotation(float NewAngle)
{
	RotationAngle = NewAngle;
	Sprite.setRotation(RotationAngle);
	SetRelativeLocation(GetRelativeLocation());
}
