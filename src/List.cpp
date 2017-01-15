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
List::Node::Node(int _value, Node* nd) : value(_value), next(nd)
{

}

List::List() : head{ nullptr }
{

}

List::~List()
{
	while (head->next != nullptr)
	{

	}
}

void List::push_back(int value)
{
    Node* n = new Node{ value, head };
    head = n;
}

int List::pop_back()
{
	Node* tmp = head;
	int value = tmp->value;
	head = tmp->next;
	delete tmp;
	return value;
}
