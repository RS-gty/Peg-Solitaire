#include "Event.h"

Event::Event()
{
}

void Event::Add(void (*func)(void))
{
	Funcs.push_back(func);
}

void Event::Trigger()
{
	for (auto func : Funcs)
	{
		func();
	}
}