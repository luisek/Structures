#include "Stack.h"
using namespace mpb;

Stack::Stack() :element{}
{
}

Stack::Stack(int item) : element{ item }
{
}

int Stack::pop()
{
	return element;
}

void Stack::push(int value)
{
	element = value;
}

bool Stack::empty()
{
	return false;
}