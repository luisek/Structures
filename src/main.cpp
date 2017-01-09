#include "Stack.hpp"
#include <iostream>

int main(int argc,char* argv[])
{
	mpb::Stack<int> inStack{};

	auto inc = 100 * 100 * 1000;
	for (auto i = 0; i < inc; ++i)
	{
		inStack.push(i + 1);
	}

	for (auto i = 0; i < inc; ++i)
	{
		std::cout << inStack.pop() << ', ';
	}
	return 0;
}
