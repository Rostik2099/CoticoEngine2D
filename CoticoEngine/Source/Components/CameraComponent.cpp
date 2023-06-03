#include "CameraComponent.h"
#include "Core/CEngine.h"

CameraComponent::CameraComponent()
{
	CameraView.reset(sf::FloatRect(0, 0, 1280, 720));
	CEngine::Get()->SetCamera(&CameraView);
}

void CameraComponent::SetWorldLocation(CVector NewLoc)
{
	CameraView.setCenter((NewLoc + GetLocalOffset()).ToSFVector());
	BaseComponent::SetWorldLocation(NewLoc);
}
