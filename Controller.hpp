#ifndef MODEL
#define MODEL
#include "Model.hpp"
#endif
#include "View.hpp"

class Application
{
private:
	unsigned int rows;
	unsigned int cols;
	World *world;
	Renderer *renderer;
	Camera *camera;

	//modifies rows and cols to current terminal's rows and cols
	void getWinSize();
public:
	Application();
	~Application();

	void run();
};
