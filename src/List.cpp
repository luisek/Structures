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

List::List() : head{ nullptr }, tail{nullptr}
{

}

List::List(std::initializer_list<int> values) : List()
{
	for (const auto& x : values)
	{
		push_back(x);
	}
}

List::List(const List& lList) : List()
{
	Node* temp = lList.head;
	while (temp)
	{
		push_back(temp->value);
		temp = temp->next;
	}
}

List& List::operator=(const List& lList)
{
	Node* temp = lList.head;
	while (temp)
	{
		push_back(temp->value);
		temp = temp->next;
	}
	return *this;
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
	if (nullptr == head)
	{
		head = new Node{value, nullptr};
		tail = head;
		++count;
		return;
	}
	tail->next = new Node{ value, nullptr };
	tail = tail->next;
	++count;
}

void List::push_front(int value)
{
	if (nullptr == head)
	{
		Node* newNode = new Node{ value, head };
		tail = head = newNode;
	}
	Node* newNode = new Node{value, head};
	head = newNode;
}

int List::pop_back()
{
	int retValue;
	if (empty())
	{
		throw ListException("Can't pop from empty list");
	}
	if (head == tail)
	{
		retValue = head->value;
		delete head;
		head = tail = nullptr;
		--count;
		return retValue;
	}

	Node* current = head;
	while (current->next != tail)
	{
		current = current->next;
	}
	retValue = tail->value;
	delete tail;
	tail = current;
	tail->next = nullptr;
	--count;
	return retValue;
}

int List::pop_front()
{
	if (!head)
		throw ListException("Can't pop from empty list");
	Node* newHead = head->next;
	int retValue = head->value;
	delete head;
	head = newHead;
	return retValue;
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