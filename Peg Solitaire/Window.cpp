#include "Window.h"
#include <stdio.h>

Window::Window(Grid &g, bool &c)
{
    this->grid = &g;
	this->isPawn = g.isPawn;
	this->closeFlag = &c;
    int size = g.width * g.height;
    
}

void Window::DrawGridLine()
{
    for (int i = 0; i <= this->grid->width; i++)
    {
        line(i * 100, 100, i * 100, this->grid->height * 100 + 100);
    }
    for (int j = 0; j <= this->grid->height; j++)
    {
        line(0, j * 100 + 100, this->grid->width * 100, j * 100 + 100);
    }
}

void Window::DrawPawn()
{
	COLORREF c = getfillcolor();
    for (int i = 0; i < this->grid->width; i++) {
        for (int j = 0; j < this->grid->height; j++) {
            if (this->isPawn[i][j] == 1) {
                if (grid->selectedx == i && grid->selectedy == j) {
                    setfillcolor(RGB(200, 0, 0));
                }
                else {
                    setfillcolor(RGB(255, 215, 0));
				}
                solidcircle(i * 100 + 50, j * 100 + 150, 30);
            }
        }
    }
	setfillcolor(c);
}


void Window::ClearPawn(int x, int y)
{
    if (x < 0 || y < 0 || x >= this->grid->width || y >= this->grid->height) {
        return;
    }
	this->isPawn[x][y] = 0;
    clearrectangle(x * 100 + 1, y * 100 + 101, (x + 1) * 100 - 1, (y + 1) * 100 + 99);
}

void Window::Display()
{
    initgraph(this->grid->width*100, this->grid->height*100+100);
	this->DrawGridLine();
}

void Window::CheckClose()
{
    if (*this->closeFlag) {
        closegraph();
    }
}

void Window::AddLeftMouseEvent(void (*func)(void))
{
    this->LeftMouseEvent.Add(func);
}

void Window::AddRightMouseEvent(void (*func)(void))
{
    this->RightMouseEvent.Add(func);
}

void Window::GetMouseGridPos(short x, short y)
{
    if (y > 100) {
        this->MouseGridx = (int)(x) / 100;
        this->MouseGridy = (int)(y - 100) / 100;
        return;
    }
	this->MouseGridx = -1;
	this->MouseGridy = -1;
}

int Window::ListenEvents()
{
	// Mouse event handling
    peekmessage(&m, EM_MOUSE);
    GetMouseGridPos(m.x, m.y);
	

    static int Ltrigger = 0;
	static int Rtrigger = 0;
    
    if (m.message == WM_LBUTTONDOWN)
    {
        this->grid->SetMouseGridPos(this->MouseGridx, this->MouseGridy);
        Ltrigger = 1;
    }
    else if (m.message == WM_LBUTTONUP && Ltrigger == 1)
    {
        Ltrigger = 0;
		printf("Left mouse button clicked at (%d, %d)\n", this->MouseGridx, this->MouseGridy);
		this->LeftMouseEvent.Trigger();
    }
    else if (m.message == WM_RBUTTONDOWN)
    {
        this->grid->SetMouseGridPos(this->MouseGridx, this->MouseGridy);
		Rtrigger = 1;
    }
    else if (m.message == WM_RBUTTONUP && Rtrigger == 1)
    {
        Rtrigger = 0;
        this->RightMouseEvent.Trigger();
    }
	// Grid event handling
	
    DrawPawn();

	// Close check
	this->CheckClose();


    return 1;
}