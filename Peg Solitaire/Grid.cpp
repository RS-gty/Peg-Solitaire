#include "Grid.h"

Grid::Grid(int width, int height)
{
	this->width = width;
	this->height = height;
    this->isPawn = (int**)malloc(sizeof(int*) * this->width);
    for (int i = 0; i < this->width; i++) {
        this->isPawn[i] = (int*)malloc(sizeof(int) * this->height);
        for (int j = 0; j < this->height; j++) {
            this->isPawn[i][j] = 1;
        }
    }
	this->selectedx = -1;
	this->selectedy = -1;
}

void Grid::SetMouseGridPos(int x, int y)
{
    this->MouseGridx = x;
    this->MouseGridy = y;
}

void Grid::Select()
{
    this->movedx = -1;
    this->movedy = -1;
    if (this->selectedx == this->MouseGridx && this->selectedy == this->MouseGridy) {
        this->selectedx = -1;
        this->selectedy = -1;
		return;
    }
    if (this->isPawn[this->MouseGridx][this->MouseGridy] == 0) {
		int dx = this->MouseGridx - this->selectedx;
		int dy = this->MouseGridy - this->selectedy;
        if ((abs(dx) == 2 && dy == 0) || (abs(dy) == 2 && dx == 0) && this->isPawn[this->selectedx+dx/2][this->selectedy+dy/2]) {
			std::cout << "Move from (" << this->selectedx << ", " << this->selectedy << ") to (" << this->MouseGridx << ", " << this->MouseGridy << ")\n";
			this->isPawn[this->MouseGridx][this->MouseGridy] = 1;
			this->isPawn[this->selectedx][this->selectedy] = 0;
            this->isPawn[this->selectedx + dx / 2][this->selectedy + dy / 2] = 0;
            this->movedx = this->selectedx;
			this->movedy = this->selectedy;
			this->selectedx = -1;
			this->selectedy = -1;
        }
        return;
	}
	this->selectedx = this->MouseGridx;
	this->selectedy = this->MouseGridy;
    return;
}