#pragma once
#include "BaseComponent.h"

class CameraComponent : public BaseComponent
{
public:
	CameraComponent();

	void SetWorldLocation(CVector NewLoc) override;

private:
	sf::View CameraView;
};

