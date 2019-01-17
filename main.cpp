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
	float angle = 0;
	for (int i = 0; i < 90; ++i)
	{
	std::cout << camera.castRayStatic(angle, 40) << ", " << camera.castRayMixed(angle, 40) << std::endl;
	++angle;
	}

	Renderer renderer;
	renderer.render(&world);
	return 0;
}
