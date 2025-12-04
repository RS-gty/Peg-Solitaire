#include <iostream>
#include <easyx.h>
#include <graphics.h>
#include "Window.h"

bool closeFlag;
Grid grid(7, 7);
Window win(grid, closeFlag);

void printHello()
{
	std::cout << "Hello, World!" << std::endl;
}

void onClose()
{
	closeFlag = true;
	std::cout << "Window is closing." << std::endl;
}

int main()
{
	closeFlag = false;

	void GselectWrapper();
	
	win.Display();

	win.AddLeftMouseEvent(printHello);
	win.AddLeftMouseEvent(GselectWrapper);
	win.AddRightMouseEvent(onClose);

	win.ClearPawn(3, 3);
    while (win.ListenEvents());
    return 0;
}

void GselectWrapper()
{
	grid.Select();
	if (grid.movedx != -1 && grid.movedy != -1) {
		win.ClearPawn(grid.movedx, grid.movedy);
		win.ClearPawn((grid.movedx + grid.MouseGridx) / 2, (grid.movedy + grid.MouseGridy) / 2);
	}
	std::cout << "Grid selected at (" << grid.selectedx << ", " << grid.selectedy << ")" << std::endl;
}