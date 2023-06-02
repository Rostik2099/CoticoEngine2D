#include "CActor.h"
#include "Components/BaseComponent.h"
#include "Render/Renderer.h"
#include "Components/SpriteComponent.h"
#include "Core/World.h"

CActor::CActor() {}

CActor::~CActor() {}

void CActor::Tick(float DeltaTime)
{
    for (auto [id, comp] : Components)
    {
        comp->Tick(DeltaTime);
    }

    this->dt = DeltaTime;
}

void CActor::Destroy()
{
    World::Get()->AddActorForDeletion(this);
}

void CActor::InitComponent(std::shared_ptr<BaseComponent> Component, std::string ID)
{
    Component->SetUUID(ID);
    Component->BeginPlay();

    if (dynamic_cast<SpriteComponent*>(Component.get()))
    {
        Renderer::Get()->AddSprite(Ref<SpriteComponent>(std::dynamic_pointer_cast<SpriteComponent>(Component)));
    }
}

World* CActor::GetWorld()
{
    return World::Get();
}
