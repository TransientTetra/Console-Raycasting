#include "Model.hpp"
#include <cmath>

///////////////////////////////////////////////////////////////////////////////
//World
World::World(int height, int width) :
height(height), width(width)
{
	map = new char*[height];
	blockArray = new Block*[height];
	for (int i = 0; i < height; ++i)
	{
		map[i] = new char[width];
		blockArray[i] = new Block[width];
	}
}


World::~World()
{
	for (int i = 0; i < height; ++i)
		delete map[i];
	delete map;
}


void World::load(char *model, int blockSize)
{
	int index = 0;
	Point currentUpperleft(0, 0);
	Point currentDownright(blockSize, blockSize);

	//copying model to map
	//copying model to blockArray
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (model[index] == '#')
			{
				map[i][j] = model[index];
				blockArray[i][j].solid = true;

			}
			else
			{
				map[i][j] = '.';
				blockArray[i][j].solid = false;
			}

			blockArray[i][j].upperleft = currentUpperleft;
			blockArray[i][j].downright = currentDownright;

			++index;
			currentUpperleft.x += blockSize;
			currentDownright.x += blockSize;
		}
		currentUpperleft.x = 0;
		currentDownright.x = blockSize;
		currentUpperleft.y += blockSize;
		currentDownright.y += blockSize;
	}
} 

bool World::isInside(Point point)
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (blockArray[i][j].isInside(point))
				return true;
		}
	}
	return false;
}

int World::getWidth()
{return width;}

int World::getHeight()
{return height;}

char **World::getMap()
{return map;}

///////////////////////////////////////////////////////////////////////////////
//Point
Point::Point(){};

//Point::Point(const Point &other)
//{
	//x = other.x;
	//y = other.y;
//}

Point::Point(float x, float y)
: x(x), y(y)
{}
///////////////////////////////////////////////////////////////////////////////
//Block
bool Block::isInside(Point point)
{
	if (!solid)
		return false;
	if (point.x >= upperleft.x && point.x <= downright.x)
		if (point.y <= downright.y && point.y >= upperleft.y)
		{
			return true;
		}
	return false;
}

///////////////////////////////////////////////////////////////////////////////
//Camera
float Camera::castRayStatic(float angle)
{
	//move this to ray?
	angle += this->angle;
	Point currPosition = position;
	float step = 0.1;
	float sum = 0;
	while (1)
	{
		currPosition.x = step * sin(angle);
		currPosition.y = step * cos(angle);
		//unfinished algorithm
	}
}
