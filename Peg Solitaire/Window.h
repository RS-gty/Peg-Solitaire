#pragma once

#include "Grid.h"
#include "Event.h"

class Window
{
	public:
	Window(Grid &g, bool &c);

	void DrawGridLine();
	void DrawPawn();
	void ClearPawn(int x, int y);

	void Display();
	void CheckClose();

	void AddLeftMouseEvent(void (*func)(void));
	void AddRightMouseEvent(void (*func)(void));
	void GetMouseGridPos(short x, short y);

	int ListenEvents();

private:
	bool* closeFlag;
	int MouseGridx, MouseGridy;

	Grid* grid;
	ExMessage m;
	int **isPawn;

	Event LeftMouseEvent;
	Event RightMouseEvent;
};
