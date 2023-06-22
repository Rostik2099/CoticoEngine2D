#include "CameraComponent.h"
#include "Render/Renderer.h"
#include "Core/CEngine.h"
#include "Core/CActor.h"

CameraComponent::CameraComponent()
{
	int width, height;
	Renderer::Get()->GetWindowSize(width, height);
	CameraView.reset(sf::FloatRect(0, 0, width, height));
	CEngine::Get()->SetCamera(this);
}

void CameraComponent::SetWorldLocation(CVector NewLoc)
{
	CameraView.setCenter((NewLoc).ToSFVector());
	BaseComponent::SetWorldLocation(NewLoc);
}

void CameraComponent::SetRelativeLocation(CVector Offset)
{
	if (GetOwner())
		CameraView.setCenter((GetOwner()->GetActorLocation() + Offset).ToSFVector());
	BaseComponent::SetRelativeLocation(Offset);
}

void CameraComponent::ResetView(sf::FloatRect NewView)
{
	CameraView.reset(NewView);
	SetRelativeLocation(GetRelativeLocation());
}

