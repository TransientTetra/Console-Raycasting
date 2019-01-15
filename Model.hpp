class Point
{
public:
	float x;
	float y;
};

class Ray
{
private:

public:
};

class Block
{
private:
	Point upperleft;
	Point downright;
public:
	//takes point, checks if it lies in this block
	//gives corresponding answer
	bool isInside(Point point);
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
	//initializes map as 2d char array of height and width
	World(int height, int width);

	//deletes initialized map
	~World();

	//loads given map arrangement from char array
	void load(char *model);

	int getHeight();

	int getWidth();

	//returns pointer to map
	char **getMap();
};
