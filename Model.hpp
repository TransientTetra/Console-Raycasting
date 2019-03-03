class Point
{
public:
	float x;
	float y;

	Point();
	//Point(const Point &other);
	Point(float x, float y);
};

class Block
{
private:
public:
	Point upperleft;
	Point downright;
	bool solid;

	//takes point, checks if it lies in this block
	//gives corresponding answer
	bool isInside(Point point);
};

class World
{
private:
	char **map;
	Block **blockArray;
	int blockSize;
	int height;
	int width;
public:
	//initializes map as 2d char array of height and width
	World(int height, int width);

	//deletes initialized map
	~World();

	//loads given map arrangement from char array
	void load(char *model, int blockSize);

	//checks all blocks if given point is inside of them
	//takes Point, gives yes/no
	bool isInside(Point point);

	int getHeight();

	int getWidth();

	int getBlockSize();

	//returns pointer to map
	char **getMap();

	//debugging
///	void printBlocks()
///	{
///		for (int i = 0; i < height; ++i)
///		{
///			for (int j = 0; j < width; ++j)
///			{
///				std::cout << blockArray[i][j].upperleft.x << ", " << blockArray[i][j].upperleft.y << ", " << blockArray[i][j].downright.x << ", " << blockArray[i][j].downright.y << std::endl;
///				
///			}
///		}
///	}
};

class Camera
{
private:
	Point position;
	float angle;
	World *world;
public:
	Camera(Point position, float angle, World *world);
	float castRayStatic(float angle, float renderDistance);
	float castRayMixed(float angle, float renderDistance);

	//adds angle to current angle
	void rotate(float angle);
	//moves camera by given dx and dy, adding it to current coords
	void move(float dx, float dy);

};
