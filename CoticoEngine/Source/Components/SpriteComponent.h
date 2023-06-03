#pragma once
#include "BaseComponent.h"
#include<SFML/Graphics.hpp>

class CActor;

class SpriteComponent : public BaseComponent
{
public:
	SpriteComponent();
	~SpriteComponent();

	void SetTexture(std::string path);
	void SetScale(CVector NewScale);
	sf::Sprite& GetSprite() { return this->Sprite; };
	void SetWorldLocation(CVector NewLoc) override;

protected:
	sf::Sprite Sprite;
	sf::Texture Texture;
};

