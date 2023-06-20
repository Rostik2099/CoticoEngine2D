#pragma once
#include <vector>
#include "Types/SoftRef.h"

class CActor;

class IActorEventCallback
{
public:
	virtual void Run(Ref<CActor>) = 0;
};

template<typename T>
class ActorEventCallback : public IActorEventCallback
{
public:
	void Run(Ref<CActor> actor) override
	{
		if (listener)
		{
			(listener.GetRaw()->*function)(actor);
		}
	};

	ActorEventCallback(T* object, void(T::* func)(Ref<CActor> actor))
	{
		this->listener = Ref<T>(object);
		this->function = func;
	};

private:
	void(T::* function)(Ref<CActor> actor);
	Ref<T> listener;
};

class ActorEvent
{
public:
	ActorEvent();
	~ActorEvent();

	template<typename T>
	void AddListener(T * listener, void(T:: * funct)(Ref<CActor> actor))
	{
		IActorEventCallback* newCallback = new ActorEventCallback(listener, funct);
		callbacks.push_back(newCallback);
	};

	virtual void Broadcast(Ref<CActor> actor);
protected:
	std::vector<IActorEventCallback*> callbacks;
};