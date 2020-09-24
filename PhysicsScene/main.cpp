#include "PhysicsSceneApp.h"

int main() {
	
	// allocation
	auto app = new PhysicsSceneApp();

	// initialise and loop
	app->run("AIE", 1920, 1080, false);

	// deallocation
	delete app;

	return 0;
}