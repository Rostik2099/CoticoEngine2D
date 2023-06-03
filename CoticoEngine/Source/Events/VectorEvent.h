#pragma once
#include <vector>
#include "Types/SoftRef.h"
#include "Types/CVector.h"

class IVectorEventCallback
{
public:
	virtual void Run(CVector) = 0;
};

template<typename T>
class VectorEventCallback : public IVectorEventCallback
{
public:
	void Run(CVector vector) override
	{
		if (listener)
		{
			(listener.GetRaw()->*function)(vector);
		}
	};

	VectorEventCallback(T* object, void(T::* func)(CVector vector))
	{
		this->listener = Ref<T>(object);
		this->function = func;
	};

private:
	void(T::* function)(CVector vector);
	Ref<T> listener;
};

class VectorEvent
{
public:
	VectorEvent();
	~VectorEvent();

	template<typename T>
	void AddListener(T * listener, void(T:: * funct)(CVector vector))
	{
		IVectorEventCallback* newCallback = new VectorEventCallback(listener, funct);
		callbacks.push_back(newCallback);
	};

	virtual void Broadcast(CVector vector);
protected:
	std::vector<IVectorEventCallback*> callbacks;
};