#ifndef MODEL
#define MODEL
#include "Model.hpp"
#endif
class Renderer
{
private:
	char **buffer;
	int bufferHeight;
	int bufferWidth;
public:
	Renderer(int height, int width);
	~Renderer();
	//renders specified world to console window
	void render(Camera *camera, float fov, float renderDistance);

	void draw()
	{
	}
};
