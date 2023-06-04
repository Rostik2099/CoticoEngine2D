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
	std::string GetLayer() { return this->Layer; };
	void SetLayer(std::string NewLayer) { this->Layer = NewLayer; };

protected:
	sf::Sprite Sprite;
	sf::Texture Texture;
	std::string Layer = "0Default";
	CVector ImageOffset;
};

