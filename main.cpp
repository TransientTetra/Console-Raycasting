#include <iostream>
#include "Controller.hpp"
int main()
{
	World world(5, 6);
	char map[30] =
	{'#', '#', '#', '#', '#','#',
	'#', 'k', 'k', 'k', 'k', '#',
	'#', 'k', 'k', '#', 'k', '#',
	'#', 'k', 'k', 'k', 'k', '#',
	'#', '#', '#', '#', '#', '#'};
	world.load(map, 10);

	Camera camera(Point(35, 15), 0, &world);


	Renderer renderer(50, 50);
	renderer.render(&camera, 90, 40);
	return 0;
}
