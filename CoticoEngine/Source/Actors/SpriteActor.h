#pragma once
#include "Core/CActor.h"
#include "Components/SpriteComponent.h"
#include "Types/SoftRef.h"

class SpriteActor : public CActor
{
public:
	SpriteActor()
	{
		Sprite = SpawnComponent<SpriteComponent>();
	};

	Ref<SpriteComponent> GetSprite() { return this->Sprite; };

private:
	Ref<SpriteComponent> Sprite;
};

