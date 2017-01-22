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

List::List(std::initializer_list<int> values) : head{nullptr}
{
	for (const auto& x : values)
	{
		push_back(x);
	}
}

List::~List()
{
	while (head != nullptr)
	{
		Node* tmp = head;
		head = tmp->next;
		delete tmp;
	}
}

void List::push_back(int value)
{
    Node* n = new Node{ value, head };
    head = n;
	++count;
}

void List::push_front(int value)
{
	
}

int List::pop_back()
{
	Node* tmp = head;
	int value = tmp->value;
	head = tmp->next;
	delete tmp;
	--count;
	return value;
}

List::Node* List::find(int valueToFind)
{
	Node* current = head;
	while (nullptr != current)
	{
		if (valueToFind != current->value)
		{
			current = current->next;
		}
		else
		{
			break;
		}
	}
	return current;
}