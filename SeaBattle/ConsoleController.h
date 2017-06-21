#ifndef CONSOLECONTROLLER_H
#define CONSOLECONTROLLER_H

#include "IController.h"
#include "Game.h"

class ConsoleController : public IController {
public:
	ConsoleController(Game* game);
	~ConsoleController();
	void start() override;
private:
	Game* game_;
};

#endif // !CONSOLECONTROLLER_H

