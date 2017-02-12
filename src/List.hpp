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

    template<typename T>
    struct Node
    {
        T value;
        Node<T>* next = nullptr;
        Node() = default;
    };
    

    template<typename T>
    class List
    {

    public:


        List();

        List(std::initializer_list<T> values);
        ~List();
        List(const List<T>& lList);
        List<T>& operator=(const List<T>& lList);
        List(List<T>&& rList);
        List<T>& operator=(List<T>&& rList);

        void push_back(T value);
        T pop_back();
        void push_front(T value);
        T pop_front();

        /*Node<T>* find(T valueToFind);*/

        inline bool empty() const;
        inline int countElements() const;
    private:
        Node<T>* head;
        Node<T>* tail;
        int count = 0;
    };


    template<typename T>
    inline bool List<T>::empty() const
    {
        return nullptr == head && count == 0 ? true : false;
    }

    template<typename T>
    inline int List<T>::countElements() const
    {
        return count;
    }


    template<typename T>
    List<T>::List() : head{ nullptr }, tail{ nullptr }
    {

    }

    template<typename T>
    List<T>::List(std::initializer_list<T> values) : List<T>()
    {
        for (const auto& x : values)
        {
            push_back(x);
        }
    }

    template<typename T>
    List<T>::~List()
    {
        while (head != nullptr)
        {
            Node<T>* tmp = head;
            head = tmp->next;
            delete tmp;
        }
    }

    template<typename T>
    List<T>::List(const List<T>& lList) : List<T>()
    {
        Node<T>* temp = lList.head;
        while (temp)
        {
            push_back(temp->value);
            temp = temp->next;
        }
    }

    template<typename T>
    List<T>& List<T>::operator=(const List<T>& lList)
    {
        Node<T>* temp = lList.head;
        while (temp)
        {
            push_back(temp->value);
            temp = temp->next;
        }
        return *this;
    }

    template<typename T>
    List<T>::List(List<T>&& rList) : head{ rList.head }, tail{ rList.tail }, count{ rList.count }
    {
        rList.head = nullptr;
        rList.tail = nullptr;
        rList.count = 0;
    }

    template<typename T>
    List<T>& List<T>::operator=(List<T>&& rList)
    {
        head = rList.head;
        rList.head = nullptr;
        tail = rList.tail;
        rList.tail = nullptr;
        count = rList.count;
        rList.count = 0;
        return *this;
    }

    template<typename T>
    void List<T>::push_back(T value)
    {
        if (nullptr == head)
        {
            Node<T>* newHead = new Node<T>;
            newHead->value = value;
            newHead->next = nullptr;
            head = newHead;
            tail = head;
            ++count;
            return;
        }
        Node<T>* newNext = new Node<T>;
        newNext->value = value;
        newNext->next = nullptr;
        tail->next = newNext;
        tail = tail->next;
        ++count;
    }

    template<typename T>
    T List<T>::pop_back()
    {
        T retValue;
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

        Node<T>* current = head;
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

    template<typename T>
    void List<T>::push_front(T value)
    {
        if (nullptr == head)
        {
            
            Node<T>* newNode = new Node<T>;
            newNode->value = value;
            newNode->next = head;
            tail = head = newNode;
            ++count;
            return;
        }
        Node<T>* newNode = new Node<T>;
        newNode->value = value;
        newNode->next = head;
        head = newNode;
        ++count;
    }

    template<typename T>
    T List<T>::pop_front()
    {
        if (!head)
            throw ListException("Can't pop from empty list");
        Node<T>* newHead = head->next;
        T retValue = head->value;
        delete head;
        head = newHead;
        --count;
        return retValue;
    }

    /*template<typename T>
    List<T>::Node<T>* List<T>::find(T valueToFind)
    {
        Node<T>* current = head;
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
    }*/

}
#endif
