#pragma once

#include<memory>

template<typename T>
class Ref
{
public:
	Ref() {};
	
	Ref(T* Ref) 
	{

	};

	Ref(std::shared_ptr<T> ref) 
	{
		ptr = ref;
	};

	T* operator->() const { return this->ptr.lock().get(); };

	operator bool() const
	{
		if (!ptr.expired()) return true;
		else return false;
	};

	std::weak_ptr<T> Get() { return this->ptr; };
	T* GetRaw() { return this->ptr.lock().get(); };

private:
	std::weak_ptr<T> ptr;
};