#include "Stack.hpp"
#include "List.hpp"
#include <iostream>

int main(int argc,char* argv[])
{
	mpb::Stack<int> inStack{};
	mpb::List<int> myList;

	auto inc = 100 * 100 * 1000;
	for (auto i = 0; i < inc; ++i)
	{
		inStack.push(i + 1);
	}

	for (auto i = 0; i < inc; ++i)
	{
		inStack.pop();
	}

	std::cout <<std::endl;

	for(auto i = 0; i < inc; ++i)
	{
		myList.push_back(i);
	}
	for(auto i = 0; i < inc; ++i)
	{
		myList.pop_front();
	}
	return 0;
}
