#pragma once
#include <vector>

class Event
{
public:
	Event();

	std::vector<void (*)(void)> Funcs;
	std::vector<void (*)(int x, int y)> FuncsXY;

	void Add(void (*func)(void));
	void Trigger();
};
