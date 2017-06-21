#include "Game.h"
#include "ConsoleView.h"
#include "ConsoleController.h"

int main()
{
	Game game;
	ConsoleView view(&game);
	ConsoleController controller(&game);
	view.show();
	controller.start();

	return 0;
}