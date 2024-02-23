#include "Observer.h"

Observer* Observer::_instance;
Observer* Observer::getInstance() {
	if (_instance == nullptr) {
		_instance = new Observer();
	}
	return _instance;
}

void Observer::registerEvent(std::string type, std::function<void(void*)> callback)
{
	auto observers = getObservers(type);
	observers->push_back(callback);
	//log("so   luong:%d", observers->size());
}

void Observer::unRegisterEvent(std::string type, std::function<void(void*)> callback)
{
	auto observers = getObservers(type);
	if (observers) {
		auto it = std::remove_if(observers->begin(), observers->end(),
			[&callback](const std::function<void(void*)>& func) {
				return func.target_type() == callback.target_type();
			});

		// Erase the removed elements
		observers->erase(it, observers->end());
	}
}

void Observer::notify(std::string type, void* data)
{
	auto observers = getObservers(type);
	for (int i = 0; i < observers->size(); ++i)
	{
		observers->at(i)(data);
	}
}

std::vector<std::function<void(void*)>>* Observer::getObservers(std::string type)
{
	if (_eventTypes.find(type) == _eventTypes.end())
	{
		_eventTypes.insert({ type, new std::vector<std::function<void(void*)>>() });
	}
	//log("soluong:%d", _eventTypes[type]->size());
	return _eventTypes.at(type);
}