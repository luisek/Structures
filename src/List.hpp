#ifndef __LIST_H___
#define __LIST_H___
#include <string>
#include <stdexcept>

namespace mpb
{
	class ListException : std::logic_error
	{
	public:
		ListException(const std::string& what_arg);
		~ListException();
		const char* what() const noexcept override;
	private:
		std::string message;
	};

	class List
	{

	public:
		struct Node
		{
			int value;
			Node* next = nullptr;
			Node(int _value, Node* node);
		};
	    List();
		List(std::initializer_list<int> values);
		~List();

        void push_back(int value);
		int pop_back();

		void push_front(int value);
		Node* find(int valueToFind);
		inline bool empty() const
		{
			return nullptr == head;
		}
		inline int countElements() const
		{
			return count;
		}
    private:
        Node* head;
		Node* tail;
		int count = 0;
	};
}
#endif
