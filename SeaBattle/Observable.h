#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <vector>

#include "Observer.h"

class Observable
{
public:
	~Observable();
	void addObserver(Observer* observer);	
	void notifyUpdate();
private:
	std::vector<Observer*> observers_;
};

#endif // OBSERVABLE_H
