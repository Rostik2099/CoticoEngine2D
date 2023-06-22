#pragma once
#include "BaseComponent.h"

class CameraComponent : public BaseComponent
{
public:
	CameraComponent();

	void SetWorldLocation(CVector NewLoc) override;
	void SetRelativeLocation(CVector Offset) override;
	sf::View* GetCameraView() { return &this->CameraView; };
	void ResetView(sf::FloatRect NewView);

private:
	sf::View CameraView;
};

