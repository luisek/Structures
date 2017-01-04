#ifndef __STACK_H___
#define __STACK_H___
namespace mpb
{
	class Stack
	{
	public:
		Stack(int size = 10);
		explicit Stack(int item, int size=10);
		~Stack();

		int pop();
		void push(int value);
		bool empty();
	private:
		int* elements;
		int stackSize;
		int currentElement = -1;

	};
}

#endif