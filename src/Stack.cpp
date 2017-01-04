#include "Stack.h"
using namespace mpb;

Stack::Stack(int size) : stackSize{size}
{
	elements = new int[stackSize];
}

Stack::Stack(std::initializer_list<int> items, int size) : stackSize{size}
{
	if (size < items.size())
		throw StackException("too many items - stack size should be equal to items count");
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
	canPopElement();
	auto value = elements[currentElement];
	decrementIndexes();
	return value;
}

void Stack::push(int value)
{
	checkStackSize();
	elements[inserter] = value;
	incrementIndexes();
}

bool Stack::empty()
{
	return 0 > currentElement ? true : false;
}

void Stack::allocateNewStack(int newStackSize)
{
	int* newStack = new int[newStackSize];
	for (auto i = 0; i < inserter; ++i)
	{
		newStack[i] = elements[i];
	}
	delete elements;
	elements = newStack;
}

StackException::StackException(const std::string& what_arg) : message{what_arg}, logic_error { what_arg }
{

}

StackException::~StackException()
{
}
const char* StackException::what() const
{
	return message.c_str();
}
