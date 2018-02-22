#pragma once

#include <initializer_list>
#include <memory>
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
            explicit StackImpl(std::initializer_list<T> items);
            StackImpl(const StackImpl<T>& newStack);
            StackImpl<T>& operator=(const StackImpl<T>& newStack);

            StackImpl(StackImpl<T>&& rStack);
            StackImpl<T>& operator=(StackImpl<T>&& rStack);

            T pop();
            void push(T value);
            bool empty();
        private:
            inline void incrementIndexes();
            inline void decrementIndexes();
            inline void canPopElement();
            inline void checkStackSize();
            void allocateNewStack(int newStackSize);

            std::unique_ptr<T[]> elements;
            int stackSize;
            int currentElement = -1;
            int inserter = 0;

        };


        template<typename T>
        StackImpl<T>::StackImpl(int size) : stackSize{ size }
        {
            elements = std::make_unique<T[]>(stackSize);
        }

        template<typename T>
        StackImpl<T>::StackImpl(std::initializer_list<T> items) : StackImpl(items.size())
        {
            for (auto it = items.begin(); it != items.end() && inserter < stackSize; ++it, incrementIndexes())
            {
                elements[inserter] = *it;
            }
        }

        template<typename T>
        StackImpl<T>::StackImpl(const StackImpl<T>& source) : stackSize{source.stackSize}
        {
            elements = std::make_unique<T[]>(stackSize);
            for (auto i = 0; i < source.inserter; ++i)
                push(source.elements[i]);
        }
        
        template<typename T>
        StackImpl<T>& StackImpl<T>::operator=(const StackImpl<T>& source)
        {
            //if(this == newStack) maybe
            if (elements)
                elements.reset();
            elements = std::make_unique<T[]>(source.stackSize);
            for (auto i = 0; i < source.inserter; ++i)
            {
                push(source.elements[i]);
            }
            return *this;
        }

        template<typename T>
        StackImpl<T>::StackImpl(StackImpl<T>&& source)
        {
            elements = std::move(source.elements);
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
                elements.reset();
            elements = std::move(source.elements);
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
            std::unique_ptr<T[]> newStack = std::make_unique<T[]>(newStackSize);
            for (auto i = 0; i < stackSize; ++i)
            {
                newStack[i] = elements[i];
            }
            elements.reset();
            stackSize = newStackSize;
            elements = std::move(newStack);
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
        inline void StackImpl<T>::checkStackSize()
        {
            if (stackSize == inserter)
            {
                allocateNewStack(stackSize * 2);
            }
        }
}