#pragma once

#include <iostream>
#include <easyx.h>
#include <graphics.h>

class Grid
{
	public:
	Grid(int width, int height);

	void Select();
	void SetMouseGridPos(int x, int y);
	

	int width, height;
	int selectedx, selectedy;
	int movedx, movedy;
	int MouseGridx, MouseGridy;
	int** isPawn;
	

    private:
        
		
        
};

