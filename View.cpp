#include "View.hpp"
#include <iostream>

void Renderer::render(World *world)
{
	char **ptr = world->getMap();
	for (int i = 0; i < world->getHeight(); ++i)
	{
		for (int j = 0; j < world->getWidth(); ++j)
			std::cout << ptr[i][j];
		std::cout << std::endl;
	}

}
