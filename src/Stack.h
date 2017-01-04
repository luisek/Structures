#ifndef __STACK_H___
#define __STACK_H___
#include <initializer_list>
#include <stdexcept>

namespace mpb
{
	class StackException : std::logic_error
	{
	public:
		StackException(const std::string& what_arg);
		~StackException();
		const char* what() const override;
	private:
		std::string message;
	};


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
		inline void incrementIndexes()
		{
			++currentElement;
			++inserter;
		}
		inline void decrementIndexes()
		{
			--currentElement;
			--inserter;
		}

		inline void canPopElement()
		{
			if (empty())
				throw StackException("pop from empty stack");
		}

		inline void checkStackSize()
		{
			if (stackSize == inserter)
			{
				allocateNewStack(stackSize * 2);
			}
		}

		void allocateNewStack(int newStackSize);

		int* elements;
		int stackSize;
		int currentElement = -1;
		int inserter = 0;

	};
}

#endif