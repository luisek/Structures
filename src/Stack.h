#ifndef __STACK_H___
#define __STACK_H___
namespace mpb
{
	class Stack
	{
	public:
		Stack();
		explicit Stack(int item);

		int pop();
		void push(int value);
		bool empty();
	private:
		int element;

	};
}

#endif