#pragma once
#include<string>
#include<vector>

#include"InputCallback.h"
#include"KeyMapping.h"

struct AxisParams
{
	std::string name;
	std::vector<sf::Keyboard::Key> key;
	std::vector<float> scale;
};

struct ActionParams
{
	std::string name;
	std::vector<sf::Keyboard::Key> key;
};

class InputEvent
{
public:
	InputEvent() {};

	virtual void Press(int keyIndex) { pressed = true; };
	virtual void Release() { pressed = false; };
	virtual void AddKey(sf::Keyboard::Key newKey, float scale) {};
	virtual std::vector<sf::Keyboard::Key> GetKeys() = 0;
protected:
	bool pressed = false;
};

class AxisEvent : public InputEvent
{
public:
	AxisEvent();

	void Press(int keyIndex) override;
	void Release() override;
	void AddKey(sf::Keyboard::Key newKey, float scale) override;
	std::vector<sf::Keyboard::Key> GetKeys() override;
	void SetParams(AxisParams params) { this->params = params; };
	AxisParams GetParams() { return this->params; };

	template<typename T>
	void AddListener(T* listener, void(T::* funct)(float scale))
	{
		IAxisCallback* newCallback = new AxisCallback(listener, funct);
		callbacks.push_back(newCallback);
	};

private:
	std::vector<IAxisCallback*> callbacks;
	AxisParams params;
	float scale = 0.f;
};

class ActionEvent : public InputEvent
{
public:
	ActionEvent();

	void Press(int keyIndex) override;
	void Release() override;
	void AddKey(sf::Keyboard::Key newKey, float scale) override;
	std::vector<sf::Keyboard::Key> GetKeys() override;
	void SetParams(ActionParams params) { this->params = params; };

	template<typename T>
	void AddListener(T* listener, void(T::* funct)(), ActionType actionType)
	{
		if (actionType == IE_PRESS)
		{
			IActionCallback* newCallback = new ActionCallback(listener, funct);
			pressCallbacks.push_back(newCallback);
		}
		if (actionType == IE_RELEASE)
		{
			IActionCallback* newCallback = new ActionCallback(listener, funct);
			releaseCallbacks.push_back(newCallback);
		}
	};

	ActionParams GetParams() { return this->params; };
private:
	std::vector<IActionCallback*> pressCallbacks;
	std::vector<IActionCallback*> releaseCallbacks;
	ActionParams params;
};