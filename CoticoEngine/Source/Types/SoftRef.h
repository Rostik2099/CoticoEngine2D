#pragma once

#include<memory>
#include"Utils/EngineUtils.h"

template<typename T>
class Ref
{
public:
	Ref() {};
	
	Ref(CActor* Ref) 
	{
		std::shared_ptr<T> pointer;
		pointer = std::dynamic_pointer_cast<T>(EngineUtils::GetActorByID(Ref->GetUUID()));
		this->ptr = pointer;
	};

	Ref(BaseComponent* Ref)
	{
		std::shared_ptr<T> pointer;
		pointer = std::dynamic_pointer_cast<T>(EngineUtils::GetComponentByID(Ref));
		this->ptr = pointer;
	};

	Ref(EditorLayer* Ref)
	{
		std::shared_ptr<T> pointer;
		pointer = std::dynamic_pointer_cast<T>(EngineUtils::GetEditorLayerByID(Ref));
		this->ptr = pointer;
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