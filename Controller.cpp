#include "Controller.hpp"
#include <sys/ioctl.h>
#include <iostream>

//gets current terminal's rows and cols and writes to object variables
void Application::getWinSize()
{
	struct winsize w;
	//1 is STDOUT_FILENO, written here explicite to avoid linking unistd
	ioctl(1, TIOCGWINSZ, &w);

	rows = w.ws_row;
	cols = w.ws_col;
}

Application::Application()
{
	getWinSize();
	world = new World(5, 6);
	camera = new Camera(Point(15, 15), 0, world);
	renderer = new Renderer(rows, cols);

	char map[30] =
	{'k', '#', 'k', 'k', 'k','k',
	'#', 'k', 'k', '#', 'k', 'k',
	'#', 'k', 'k', 'k', 'k', 'l',
	'#', 'k', 'k', 'k', 'k', 'l',
	'#', '#', 'k', 'k', 'k', 'k'};
	world->load(map, 10);
	initscr();
}

Application::~Application()
{
	endwin();
	delete(world);
	delete(camera);
	delete(renderer);
}

void Application::run()
{
	while(1)
	{
		renderer->render(camera, 60, 40);
		renderer->drawBuffer();
		camera->rotate(1);
	}

}
