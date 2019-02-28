#include "Controller.hpp"

//todo
//
//how to print directly to console buffer
//how to get char dimensions of console window

int main() {
	World world(5, 6);
	char map[30] =
	{'k', '#', 'k', 'k', 'k','k',
	'#', 'k', 'k', '#', 'k', 'k',
	'#', 'k', 'k', 'k', 'k', 'l',
	'#', 'k', 'k', 'k', 'k', 'l',
	'#', '#', 'k', 'k', 'k', 'k'};
	world.load(map, 10);

	Camera camera(Point(15, 15), 0, &world);

	Renderer renderer(53, 199);
	renderer.render(&camera, 60, 40);
	renderer.drawBuffer();

	return 0;
}
