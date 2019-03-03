#include "View.hpp"
#include <cmath>
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
	//setting initial angle, leftmost ray
	float angle = fov / 2.0;
	//calculating what angle to increment by
	float rayAngle = fov / bufferWidth;
	float zero = 5;

	for (int i = 0; i < bufferWidth; ++i)
	{
		float currRay = camera->castRayStatic(angle, renderDistance);
		angle -= rayAngle;

		//amount of chars that need to be drawn above block in given line
		float ceilingHeight = (bufferHeight / 2) * ((currRay) / renderDistance);

		//constructing one vertical line of buffer here
		//buffer[height][width]
		for (int j = 0; j < bufferHeight; ++j)
		{
			if (j <= ceilingHeight || j >= bufferHeight - ceilingHeight)
				buffer[j][i] = '.';
			else buffer[j][i] = '#';
		}
	}
}

void Renderer::drawBuffer()
{
	erase();
	for (int i = 0; i < bufferHeight; ++i)
	{
		for (int j = 0; j < bufferWidth; ++j)
			addch(buffer[i][j]);
	}
	refresh();
}
