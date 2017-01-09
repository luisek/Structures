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
		const char* what() const noexcept override;
	private:
		std::string message;
	};

	template <typename T>
	class Stack
	{
	public:
		Stack(int size = 10);
		explicit Stack(std::initializer_list<T> items, int size=10);
		Stack(const Stack<T>& newStack);
		Stack<T>& operator=(Stack<T> const & newStack);

	/*	Stack(Stack<T>&& rStack);
		Stack<T>& operator=(Stack<T>&& rStack);*/

		~Stack();

		T pop();
		void push(T value);
		bool empty();
	private:
		inline void incrementIndexes();
		inline void decrementIndexes();
		inline void canPopElement();
		inline void checkStackConstruction(int itemsCount, int stackSize);
		inline void checkStackSize();
		void allocateNewStack(int newStackSize);

		T* elements;
		int stackSize;
		int currentElement = -1;
		int inserter = 0;

	};


	template<typename T>
	Stack<T>::Stack(int size) : stackSize{ size }
	{
		elements = new T[stackSize];
	}

	template<typename T>
	Stack<T>::Stack(std::initializer_list<T> items, int size) : stackSize{ size }
	{
		checkStackConstruction(items.size(), stackSize);
		elements = new T[stackSize];
		for (auto it = items.begin(); it != items.end() && inserter < stackSize; ++it, incrementIndexes())
		{
			elements[inserter] = *it;
		}
	}

	template<typename T>
	Stack<T>::Stack(const Stack<T>& source) : stackSize{source.stackSize}
	{
		elements = new T[stackSize];
		for (auto i = 0; i < source.inserter; ++i)
			push(source.elements[i]);
	}
	
	template<typename T>
	Stack<T>& Stack<T>::operator=(Stack<T>const& source)
	{
		//if(this == newStack) maybe
		if (elements)
			delete elements;
		elements = new T[source.stackSize];
		for (auto i = 0; i < source.inserter; ++i)
		{
			push(source.elements[i]);
		}

		return *this;
	}

	template<typename T>
	Stack<T>::~Stack()
	{
		delete[] elements;
	}

	template<typename T>
	T Stack<T>::pop()
	{
		canPopElement();
		T value = elements[currentElement];
		decrementIndexes();
		return value;
	}

	template<typename T>
	void Stack<T>::push(T value)
	{
		checkStackSize();
		elements[inserter] = value;
		incrementIndexes();
	}

	template<typename T>
	bool Stack<T>::empty()
	{
		return 0 > currentElement ? true : false;
	}

	template<typename T>
	void Stack<T>::allocateNewStack(int newStackSize)
	{
		int* newStack = new int[newStackSize];
		for (auto i = 0; i < stackSize; ++i)
		{
			newStack[i] = elements[i];
		}
		delete[] elements;
		stackSize = newStackSize;
		elements = newStack;
	}

	template<typename T>
	inline void Stack<T>::incrementIndexes()
	{
		++currentElement;
		++inserter;
	}

	template<typename T>
	inline void Stack<T>::decrementIndexes()
	{
		--currentElement;
		--inserter;
	}

	template<typename T>
	inline void Stack<T>::canPopElement()
	{
		if (empty())
			throw StackException("pop from empty stack");
	}

	template<typename T>
	inline void Stack<T>::checkStackConstruction(int itemsCount, int stackSize)
	{
		if (stackSize < itemsCount)
			throw StackException("too many items - stack size should be equal to items count");
	}

	template<typename T>
	inline void Stack<T>::checkStackSize()
	{
		if (stackSize == inserter)
		{
			allocateNewStack(stackSize * 2);
		}
	}
}

#endif
