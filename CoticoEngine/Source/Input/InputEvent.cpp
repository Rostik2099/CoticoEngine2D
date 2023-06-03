#include "InputEvent.h"

AxisEvent::AxisEvent() {}

void AxisEvent::Press(int keyIndex)
{
	InputEvent::Press(keyIndex);
	this->scale = this->GetParams().scale[keyIndex];
	GetParams().key[keyIndex].pressed = true;
	for (auto callback : callbacks)
	{
		callback->Broadcast(AxisEvent::scale);
	}
}

void AxisEvent::Release(int keyIndex)
{
	if (pressed)
	{
		this->scale = 0;
	}
	GetParams().key[keyIndex].pressed = false;
	InputEvent::Release(keyIndex);
}

void AxisEvent::AddKey(sf::Keyboard::Key newKey, float scale)
{
	this->params.key.push_back({ newKey, false });
	this->params.scale.push_back(scale);
}

std::vector<SKey> AxisEvent::GetKeys()
{
	return this->params.key;
}

ActionEvent::ActionEvent() {}

void ActionEvent::Press(int keyIndex)
{
	if (!pressed)
	{
		for (auto callback : pressCallbacks)
		{
			callback->Broadcast();
		}
	}
	GetParams().key[keyIndex].pressed = true;
	InputEvent::Press(keyIndex);
}

void ActionEvent::Release(int keyIndex)
{
	if (pressed)
	{
		for (auto callback : releaseCallbacks)
		{
			callback->Broadcast();
		}
	}
	GetParams().key[keyIndex].pressed = false;
	InputEvent::Release(keyIndex);
}

void ActionEvent::AddKey(sf::Keyboard::Key newKey, float scale)
{
	this->params.key.push_back({ newKey, false });
}

std::vector<SKey> ActionEvent::GetKeys()
{
	return this->params.key;
}
