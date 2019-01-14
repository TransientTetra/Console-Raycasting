#include "Application.hpp"
int main()
{
	World world(5, 6);
	char map[30] =
	{'#', '#', '#', '#', '#','#',
	'#', 'k', 'k', 'k', 'k', '#',
	'#', 'k', 'k', '#', 'k', '#',
	'#', 'k', 'k', 'k', 'k', '#',
	'#', '#', '#', '#', '#', '#'};
	world.load(map);
	Renderer renderer;
	renderer.render(&world);
	return 0;
}
