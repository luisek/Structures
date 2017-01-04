#include "Stack.h"
using namespace mpb;

Stack::Stack(int size) : stackSize{size}
{
	elements = new int[stackSize];
}

Stack::Stack(std::initializer_list<int> items, int size) : stackSize{size}
{
	elements = new int[stackSize];
	for (auto it = items.begin(); it != items.end() && inserter < stackSize; ++it, incrementIndexes())
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
	if (empty())
		throw EmptyStackException("pop from empty stack");
	auto value = elements[currentElement];
	decrementIndexes();
	return value;
}

void Stack::push(int value)
{
	elements[inserter] = value;
	incrementIndexes();
}

bool Stack::empty()
{
	return 0 > currentElement ? true : false;
}

EmptyStackException::EmptyStackException(const std::string& what_arg) : message{what_arg}, logic_error { what_arg }
{

}

EmptyStackException::~EmptyStackException()
{
}
const char* EmptyStackException::what() const
{
	return message.c_str();
}
