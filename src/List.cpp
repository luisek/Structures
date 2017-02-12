#include "List.hpp"
using namespace mpb;

ListException::ListException(const std::string& what_arg) : message{what_arg}, logic_error { what_arg }
{

}

ListException::~ListException()
{
}
const char* ListException::what() const noexcept
{
	return message.c_str();
}
