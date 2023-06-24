#include "CActor.h"
#include "Components/BaseComponent.h"
#include "Render/Renderer.h"
#include "Components/SpriteComponent.h"
#include "Components/CollisionBoxComponent.h"
#include "Core/World.h"

CActor::CActor() {}

CActor::~CActor() 
{
    Components.clear();
}

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

void CActor::SetActorLocation(CVector NewLoc)
{
    Location = NewLoc;

    OnLocationChanged.Broadcast(NewLoc);
}

std::shared_ptr<BaseComponent> CActor::GetComponentWithID(std::string id)
{
    return Components[id];
}

void CActor::SetCompsOwner()
{
    for (auto [id, comp] : Components)
    {
        if (comp)
        {
            comp->SetOwner(Ref<CActor>(this));
            comp->SetRelativeLocation(comp->GetRelativeLocation());
        }
    }
}

void CActor::InitComponent(std::shared_ptr<BaseComponent> Component, std::string ID)
{
    Component->SetUUID(ID);
    Component->BeginPlay();

    if (dynamic_cast<SpriteComponent*>(Component.get()))
    {
        Renderer::Get()->AddSprite(Ref<SpriteComponent>(std::dynamic_pointer_cast<SpriteComponent>(Component)));
    }
    if (dynamic_cast<CollisionBoxComponent*>(Component.get()))
    {
        std::shared_ptr<CollisionBoxComponent> CollisionBox = std::dynamic_pointer_cast<CollisionBoxComponent>(Component);
        Renderer::Get()->AddCollisionBox(Ref<CollisionBoxComponent>(CollisionBox));
        World::Get()->AddCollision(CollisionBox);
    }
}

World* CActor::GetWorld()
{
    return World::Get();
}