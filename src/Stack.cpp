#include "Stack.h"
using namespace mpb;

Stack::Stack(int size) : stackSize{size}
{
	elements = new int[stackSize];
}

Stack::Stack(int item, int size) : stackSize{size}
{
	elements = new int[stackSize];
}

Stack::~Stack()
{
	delete[] elements;
}

int Stack::pop()
{
	auto value = elements[currentElement];
	--currentElement;
	return value;
}

void Stack::push(int value)
{
	++currentElement;
	elements[currentElement] = value;
}

bool Stack::empty()
{
	return false;
}