#pragma once

#include <vector>

#include "Observer.h"

class Observable
{
	std::vector<Observer*> observers;
public:
	void addObserver(Observer* observer);	
	void notifyUpdate();
};
