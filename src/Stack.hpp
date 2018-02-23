#pragma once

#include "Stack_impl.hpp"
#include <initializer_list>
#include <memory>


namespace mpb
{
	template <typename T>
	class Stack
	{
	public:
		Stack(int size = 10);
		Stack(const Stack<T>& rStack);
		Stack<T>& operator=(const Stack<T>& rStack);
	    Stack(Stack<T>&& rStack);
		Stack<T>& operator=(Stack<T>&& rStack);

		T pop();
		void push(T value);
		bool empty();
	private:
		std::unique_ptr<StackImpl<T>> stackImpl;
	};


	template<typename T>
	Stack<T>::Stack(int size)
	{
		stackImpl = std::make_unique<StackImpl<T>>(size);
	}

	template<typename T>
	Stack<T>::Stack(const Stack<T>& source)
	{
		stackImpl = std::make_unique<StackImpl<T>>(*(source.stackImpl));
	}

	template<typename T>
	Stack<T>& Stack<T>::operator=(const Stack<T>& source)
	{
		*stackImpl = *source.stackImpl;
	}

	template<typename T>
	Stack<T>::Stack(Stack<T>&& source)
	{
		stackImpl = std::make_unique<StackImpl<T>>(std::move(*source.stackImpl));
		source.stackImpl = nullptr;
	}

	template<typename T>
	Stack<T>& Stack<T>::operator=(Stack<T>&& source)
	{
		stackImpl = std::move(source.stackImpl);
		source.stackImpl = nullptr;
	}

	template<typename T>
	T Stack<T>::pop()
	{
		return stackImpl->pop();
	}

	template<typename T>
	void Stack<T>::push(T value)
	{
		stackImpl->push(value);
	}

	template<typename T>
	bool Stack<T>::empty()
	{
		return stackImpl->empty();
	}
}
