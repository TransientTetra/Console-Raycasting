#include <iostream>
struct Point
{
	float x;
	float y;
};

class Camera
{
private:
	struct Point position;
	float angle;
};

class World
{
private:
	char **map;
	int height;
	int width;
public:
	World(int height, int width) :
	height(height), width(width)
	{
		map = new char*[height];
		for (int i = 0; i < height; ++i)
			map[i] = new char[width];
	}
	~World()
	{
		for (int i = 0; i < height; ++i)
			delete map[i];
		delete map;
	}
	void load(char *model)
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
	void draw()
	{
		for (int i = 0; i < height; ++i)
		{
//here will be changed to not use cout
			for (int j = 0; j < width; ++j)
				std::cout << map[i][j];
			std::cout << std::endl;
		}
	}
};

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
	world.draw();
	return 0;
}
