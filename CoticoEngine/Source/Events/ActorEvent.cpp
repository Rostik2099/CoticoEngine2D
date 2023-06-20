#include "ActorEvent.h"

ActorEvent::ActorEvent() {}

ActorEvent::~ActorEvent()
{
	for (auto callback : callbacks)
	{
		delete callback;
	}
}

void ActorEvent::Broadcast(Ref<CActor> actor)
{
	for (auto callback : callbacks)
	{
		callback->Run(actor);
	}
}
