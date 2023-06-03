#include "VectorEvent.h"

VectorEvent::VectorEvent() {}

VectorEvent::~VectorEvent()
{
	for (auto callback : callbacks)
	{
		delete callback;
	}
}

void VectorEvent::Broadcast(CVector vector)
{
	for (auto callback : callbacks)
	{
		callback->Run(vector);
	}
}
