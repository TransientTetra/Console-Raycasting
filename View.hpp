#ifndef MODEL
#define MODEL
#include "Model.hpp"
#endif
#include <ncurses.h>
class Overlay
{
private:

public:

};

class Renderer
{
private:
	char **buffer;
	int bufferHeight;
	int bufferWidth;
	Overlay *overlay;

public:
	Renderer(int height, int width);
	~Renderer();

	//renders view from camera
	//takes field of view (deg) and renderDistance
	void render(Camera *camera, float fov, float renderDistance);
	//renders overlay to buffer
	void renderOverlay();

	void drawBuffer();
};
