#include "View.hpp"
#include <iostream>

Renderer::Renderer(int height, int width)
: bufferHeight(height), bufferWidth(width)
{
	buffer = new char*[height];
	for (int i = 0; i < height; ++i)
		buffer[i] = new char[width];
}

Renderer::~Renderer()
{
	for(int i = 0; i < bufferHeight; ++i)
		delete buffer[i];
	delete buffer;
}

void Renderer::render(Camera *camera, float fov, float renderDistance)
{
	float angle = -fov / 2.0;
	float rayAngle = fov / bufferWidth;
	for (int i = 0; i < bufferWidth; ++i)
	{
		std::cout << camera->castRayStatic(angle, renderDistance) << std::endl;
		angle += rayAngle;
		//constructing buffer here
	}
}


