#ifndef MODEL
#define MODEL
#include "Model.hpp"
#endif
class Renderer
{
private:
	char **buffer;
public:
	//renders specified world to console window
	void render(World *world);
};
