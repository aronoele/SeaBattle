#include "Observable.h"

void Observable::addObserver(Observer* observer) {
	observers_.push_back(observer);
}

void Observable::notifyUpdate() {
	for (auto observer : observers_) {
		observer->update();
	}
}