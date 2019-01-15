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


	Renderer renderer;
	renderer.render(&world);
	return 0;
}
