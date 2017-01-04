#ifndef __STACK_H___
#define __STACK_H___
#include <initializer_list>

namespace mpb
{
	class Stack
	{
	public:
		Stack(int size = 10);
		explicit Stack(std::initializer_list<int> items, int size=10);
		~Stack();

		int pop();
		void push(int value);
		bool empty();
	private:
		int* elements;
		int stackSize;
		int currentElement = -1;
		int inserter = 0;

	};
}

#endif