#include "Stack.h"
using namespace mpb;

Stack::Stack(int size) : stackSize{size}
{
	elements = new int[stackSize];
}

Stack::Stack(std::initializer_list<int> items, int size) : stackSize{size}
{
	elements = new int[stackSize];
	for (auto it = items.begin(); it != items.end() && inserter < stackSize; ++it, ++inserter, ++currentElement)
	{
		elements[inserter] = *it;
	}
}

Stack::~Stack()
{
	delete[] elements;
}

int Stack::pop()
{
	auto value = elements[currentElement];
	--inserter;
	--currentElement;
	return value;
}

void Stack::push(int value)
{
	elements[inserter] = value;
	++currentElement;
	++inserter;
}

bool Stack::empty()
{
	return 0 >= currentElement ? true : false;
}