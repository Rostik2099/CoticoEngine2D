#pragma once
#include <vector>
#include "Types/SoftRef.h"

class CollisionBoxComponent;

class ICollisionEventCallback
{
public:
	virtual void Run(Ref<CollisionBoxComponent>) = 0;
};

template<typename T>
class CollisionEventCallback : public ICollisionEventCallback
{
public:
	void Run(Ref<CollisionBoxComponent> collision) override
	{
		if (listener)
		{
			(listener.GetRaw()->*function)(collision);
		}
	};

	CollisionEventCallback(T* object, void(T::* func)(Ref<CollisionBoxComponent> collision))
	{
		this->listener = Ref<T>(object);
		this->function = func;
	};

private:
	void(T::* function)(Ref<CollisionBoxComponent> collision);
	Ref<T> listener;
};

class CollisionEvent
{
public:
	CollisionEvent();
	~CollisionEvent();

	template<typename T>
	void AddListener(T * listener, void(T:: * funct)(Ref<CollisionBoxComponent> collision))
	{
		ICollisionEventCallback* newCallback = new CollisionEventCallback(listener, funct);
		callbacks.push_back(newCallback);
	};

	virtual void Broadcast(Ref<CollisionBoxComponent> actor);
protected:
	std::vector<ICollisionEventCallback*> callbacks;
};