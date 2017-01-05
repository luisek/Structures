#include "Stack.hpp"
using namespace mpb;

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
