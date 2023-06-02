#include "InputEvent.h"

AxisEvent::AxisEvent() {}

void AxisEvent::Press(int keyIndex)
{
	InputEvent::Press(keyIndex);
	this->scale = this->GetParams().scale[keyIndex];
	for (auto callback : callbacks)
	{
		callback->Broadcast(AxisEvent::scale);
	}
}

void AxisEvent::Release()
{
	if (pressed)
	{
		this->scale = 0;
	}
	InputEvent::Release();
}

void AxisEvent::AddKey(sf::Keyboard::Key newKey, float scale)
{
	this->params.key.push_back(newKey);
	this->params.scale.push_back(scale);
}

std::vector<sf::Keyboard::Key> AxisEvent::GetKeys()
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
	InputEvent::Press(keyIndex);
}

void ActionEvent::Release()
{
	if (pressed)
	{
		for (auto callback : releaseCallbacks)
		{
			callback->Broadcast();
		}
	}
	InputEvent::Release();
}

void ActionEvent::AddKey(sf::Keyboard::Key newKey, float scale)
{
	this->params.key.push_back(newKey);
}

std::vector<sf::Keyboard::Key> ActionEvent::GetKeys()
{
	return this->params.key;
}
