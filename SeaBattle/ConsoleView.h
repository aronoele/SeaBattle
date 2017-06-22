#ifndef	CONSOLEVIEW_H
#define CONSOLEVIEW_H

#include "IView.h"
#include "Observer.h"
#include "Game.h"

class ConsoleView : public IView, public Observer
{
public:
	ConsoleView(Game* game);
	~ConsoleView();
	void show() override;
	void update() override;
private:
	Game* game_;
	time_t start;
};

#endif // CONSOLEVIEW_H
