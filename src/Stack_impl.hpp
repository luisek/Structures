#pragma once
#include <initializer_list>
#include <stdexcept>

namespace mpb
{
    class StackException : std::logic_error
        {
        public:
            StackException(const std::string& what_arg);
            ~StackException();
            const char* what() const noexcept override;
        private:
            std::string message;
        };

        template <typename T>
        class StackImpl
        {
        public:
            StackImpl(int size = 10);
            explicit StackImpl(std::initializer_list<T> items, int size=10);
            StackImpl(const StackImpl<T>& newStack);
            StackImpl<T>& operator=(StackImpl<T> const & newStack);

            StackImpl(StackImpl<T>&& rStack);
            StackImpl<T>& operator=(StackImpl<T>&& rStack);

            ~StackImpl();

            T pop();
            void push(T value);
            bool empty();
        private:
            inline void incrementIndexes();
            inline void decrementIndexes();
            inline void canPopElement();
            inline void checkStackConstruction(int itemsCount, int stackSize);
            inline void checkStackSize();
            void allocateNewStack(int newStackSize);

            T* elements;
            int stackSize;
            int currentElement = -1;
            int inserter = 0;

        };


        template<typename T>
        StackImpl<T>::StackImpl(int size) : stackSize{ size }
        {
            elements = new T[stackSize];
        }

        template<typename T>
        StackImpl<T>::StackImpl(std::initializer_list<T> items, int size) : stackSize{ size }
        {
            checkStackConstruction(items.size(), stackSize);
            elements = new T[stackSize];
            for (auto it = items.begin(); it != items.end() && inserter < stackSize; ++it, incrementIndexes())
            {
                elements[inserter] = *it;
            }
        }

        template<typename T>
        StackImpl<T>::StackImpl(const StackImpl<T>& source) : stackSize{source.stackSize}
        {
            elements = new T[stackSize];
            for (auto i = 0; i < source.inserter; ++i)
                push(source.elements[i]);
        }
        
        template<typename T>
        StackImpl<T>& StackImpl<T>::operator=(StackImpl<T>const& source)
        {
            //if(this == newStack) maybe
            if (elements)
                delete elements;
            elements = new T[source.stackSize];
            for (auto i = 0; i < source.inserter; ++i)
            {
                push(source.elements[i]);
            }

            return *this;
        }

        template<typename T>
        StackImpl<T>::StackImpl(StackImpl<T>&& source)
        {
            elements = source.elements;
            stackSize = source.stackSize;
            currentElement = source.currentElement;
            inserter = source.inserter;
            source.elements = nullptr;
            source.stackSize = 0;
            source.currentElement = 0;
            source.inserter = 0;
        }

        template<typename T>
        StackImpl<T>& StackImpl<T>::operator=(StackImpl<T>&& source)
        {
            if (elements)
                delete elements;
            elements = source.elements;
            stackSize = source.stackSize;
            currentElement = source.currentElement;
            inserter = source.inserter;
            source.elements = nullptr;
            source.stackSize = 0;
            source.currentElement = 0;
            source.inserter = 0;
            return *this;
        }



        template<typename T>
        StackImpl<T>::~StackImpl()
        {
            delete[] elements;
        }

        template<typename T>
        T StackImpl<T>::pop()
        {
            canPopElement();
            T value = elements[currentElement];
            decrementIndexes();
            return value;
        }

        template<typename T>
        void StackImpl<T>::push(T value)
        {
            checkStackSize();
            elements[inserter] = value;
            incrementIndexes();
        }

        template<typename T>
        bool StackImpl<T>::empty()
        {
            return 0 > currentElement ? true : false;
        }

        template<typename T>
        void StackImpl<T>::allocateNewStack(int newStackSize)
        {
            T* newStack = new T[newStackSize];
            for (auto i = 0; i < stackSize; ++i)
            {
                newStack[i] = elements[i];
            }
            delete[] elements;
            stackSize = newStackSize;
            elements = newStack;
        }

        template<typename T>
        inline void StackImpl<T>::incrementIndexes()
        {
            ++currentElement;
            ++inserter;
        }

        template<typename T>
        inline void StackImpl<T>::decrementIndexes()
        {
            --currentElement;
            --inserter;
        }

        template<typename T>
        inline void StackImpl<T>::canPopElement()
        {
            if (empty())
                throw StackException("pop from empty stack");
        }

        template<typename T>
        inline void StackImpl<T>::checkStackConstruction(int itemsCount, int stackSize)
        {
            if (stackSize < itemsCount)
                throw StackException("too many items - stack size should be equal to items count");
        }

        template<typename T>
        inline void StackImpl<T>::checkStackSize()
        {
            if (stackSize == inserter)
            {
                allocateNewStack(stackSize * 2);
            }
        }
}