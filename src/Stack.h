#ifndef __STACK_H___
#define __STACK_H___
#include <initializer_list>
#include <stdexcept>

namespace mpb
{
	class EmptyStackException : std::logic_error
	{
	public:
		EmptyStackException(const std::string& what_arg);
		~EmptyStackException();
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
				throw EmptyStackException("pop from empty stack");
		}

		void allocateNewStack(int newStackSize);

		int* elements;
		int stackSize;
		int currentElement = -1;
		int inserter = 0;

	};
}

#endif