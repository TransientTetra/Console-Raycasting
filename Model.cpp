#include "Model.hpp"
World::World(int height, int width) :
height(height), width(width)
{
	map = new char*[height];
	for (int i = 0; i < height; ++i)
		map[i] = new char[width];
}


World::~World()
{
	for (int i = 0; i < height; ++i)
		delete map[i];
	delete map;
}


void World::load(char *model)
{
	int counter = 0;
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
		{
			if (model[counter] == '#')
				map[i][j] = model[counter];
			else
				map[i][j] = '.';
			++counter;
		}
}

int World::getWidth()
{return width;}

int World::getHeight()
{return height;}

char **World::getMap()
{return map;}
