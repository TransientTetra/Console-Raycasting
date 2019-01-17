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
	{
		delete map[i];
		delete blockArray[i];
	}
	delete blockArray;
	delete map;
}

//move function to constructor??
void World::load(char *model, int blockSize)
{
	this->blockSize = blockSize;
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

int World::getBlockSize()
{return blockSize;}

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
Camera::Camera(Point position, float angle, World *world)
: position(position), angle(angle), world(world)
{}

float Camera::castRayStatic(float angle, float renderDistance)
{
	angle += this->angle;
	angle = angle * M_PI / 180.0;
	Point currPosition = position;
	float step = 0.1;
	float sum = 0.0;
	float sinAngle = sin(angle);
	float cosAngle = cos(angle);
	do
	{
		currPosition.x = currPosition.x + step * sinAngle;
		currPosition.y = currPosition.y + step * cosAngle;
		sum += step;
		if (sum >= renderDistance)
			return renderDistance;
	} while(!world->isInside(currPosition));
	sum -= step;
	return sum;
}
float Camera::castRayMixed(float angle, float renderDistance)
{
	angle += this->angle;
	angle = angle * M_PI / 180.0;
	Point currPosition = position;
	float step = world->getBlockSize();
	float sum = 0;
	float sinAngle = sin(angle);
	float cosAngle = cos(angle);
	while (1)
	{
		currPosition.x = currPosition.x + step * sinAngle;
		currPosition.y = currPosition.y + step * cosAngle;
		sum += step;
		if (world->isInside(currPosition))
			break;
		if (sum >= renderDistance)
			return renderDistance;
	}
	step = -0.1;
	while (world->isInside(currPosition))
	{
		currPosition.x = currPosition.x + step * sinAngle;
		currPosition.y = currPosition.y + step * cosAngle;
		sum += step;
	}
	return sum;
}
