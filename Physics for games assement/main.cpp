#include "Physics_for_games_assementApp.h"

int main() {
	
	// allocation
	auto app = new Physics_for_games_assementApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}