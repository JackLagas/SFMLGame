#include <iostream>

#include "game.h"



int main() {

	Game game;

	while (game.Running()) {
		


		game.GetFramerate();
		game.Update();
		game.Render();
		

	}
	return 0;
}