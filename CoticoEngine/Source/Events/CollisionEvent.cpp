#include "CollisionEvent.h"

CollisionEvent::CollisionEvent() {}

CollisionEvent::~CollisionEvent()
{
	for (auto callback : callbacks)
	{
		delete callback;
	}
}

void CollisionEvent::Broadcast(Ref<CollisionBoxComponent> collision)
{
	for (auto callback : callbacks)
	{
		callback->Run(collision);
	}
}
