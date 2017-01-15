#define BOOST_TEST_MODULE STRUCTURES
#include <boost/test/unit_test.hpp>
#include "Stack.hpp"

BOOST_AUTO_TEST_SUITE(Stack)

BOOST_AUTO_TEST_CASE(Stack_CreateAndPopElements)
{
	mpb::Stack<int> stack{{10,15,20,25,30}};
    BOOST_CHECK_EQUAL(stack.pop(), 30);
	BOOST_CHECK_EQUAL(stack.pop(), 25);
	BOOST_CHECK_EQUAL(stack.pop(), 20);
	BOOST_CHECK_EQUAL(stack.pop(), 15);
	BOOST_CHECK_EQUAL(stack.pop(), 10);
}

BOOST_AUTO_TEST_CASE(Stack_CreateAndCheckEmpty)
{
	mpb::Stack<int> stack{};
	BOOST_CHECK_EQUAL(stack.empty(), true);
}

BOOST_AUTO_TEST_CASE(Stack_CreateEmpty_PopFromEmpty)
{
	mpb::Stack<int> stack{};
	BOOST_CHECK_EQUAL(stack.empty(), true);
	BOOST_CHECK_THROW(stack.pop(), mpb::StackException);
}

BOOST_AUTO_TEST_CASE(Stack_CreateAndPush)
{
	mpb::Stack<int> stack{};
	stack.push(10);
	stack.push(20);
	BOOST_CHECK_EQUAL(stack.empty(), false);
	BOOST_CHECK_EQUAL(stack.pop(), 20);
	BOOST_CHECK_EQUAL(stack.pop(), 10);
}


BOOST_AUTO_TEST_CASE(Stack_CreateAndPushMoreThan10Elements)
{
	mpb::Stack<int> stack{};
	for (auto i = 0; i < 12; ++i)
	{
		stack.push(i + 1);
	}
	BOOST_CHECK_EQUAL(stack.empty(), false);

	for (auto i = 0; i < 12; ++i)
	{
		BOOST_CHECK_EQUAL(stack.pop(), 12 - i);
	}
	BOOST_CHECK_EQUAL(stack.empty(), true);

}

BOOST_AUTO_TEST_CASE(Stack_CreateBigStack_InitializerListExcept)
{
	BOOST_CHECK_THROW(mpb::Stack<int> stack({1,2,3,4,5,6,7,8,9,10,11,12,13}), mpb::StackException);
}

BOOST_AUTO_TEST_CASE(Stack_CreateBigStack_InitializerList)
{
	mpb::Stack<int> stack({ 1,2,3,4,5,6,7,8,9,10,11,12,13 }, 13);
	for (auto i = 0; i < 13; ++i)
	{
		BOOST_CHECK_EQUAL(stack.pop(), 13 - i);
	}
}

BOOST_AUTO_TEST_CASE(Stack_CreateBigStack)
{
	mpb::Stack<int> stack{};
	for (auto i = 0; i < 10056; ++i)
	{
		stack.push(i);
	}
	BOOST_CHECK_EQUAL(stack.pop(), 10055);
	BOOST_CHECK_EQUAL(stack.pop(), 10054);
	BOOST_CHECK_EQUAL(stack.pop(), 10053);

	stack.push(10);
	BOOST_CHECK_EQUAL(stack.pop(), 10);
	BOOST_CHECK_EQUAL(stack.empty(), false);
}

BOOST_AUTO_TEST_CASE(Stack_CopyCtorTest)
{
	mpb::Stack<int> stack{};
	
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);

	mpb::Stack<int> newStack{ stack };

	BOOST_CHECK_EQUAL(stack.pop(), newStack.pop());
	BOOST_CHECK_EQUAL(stack.pop(), newStack.pop());
	BOOST_CHECK_EQUAL(stack.pop(), newStack.pop());
	BOOST_CHECK_EQUAL(stack.pop(), newStack.pop());

	BOOST_CHECK_EQUAL(stack.empty(), true);
	BOOST_CHECK_EQUAL(newStack.empty(), true);
}

BOOST_AUTO_TEST_CASE(Stack_CopyAssignmentTest)
{
	mpb::Stack<int> stack{};

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);

	mpb::Stack<int> newStack{};

	BOOST_CHECK_EQUAL(newStack.empty(), true);

	newStack = stack;

	BOOST_CHECK_EQUAL(stack.pop(), newStack.pop());
	BOOST_CHECK_EQUAL(stack.pop(), newStack.pop());
	BOOST_CHECK_EQUAL(stack.pop(), newStack.pop());
	BOOST_CHECK_EQUAL(stack.pop(), newStack.pop());

	BOOST_CHECK_EQUAL(stack.empty(), true);
	BOOST_CHECK_EQUAL(newStack.empty(), true);
}

BOOST_AUTO_TEST_CASE(Stack_MoveCtorTest)
{
	mpb::Stack<int> stack{};

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);

	mpb::Stack<int> newStack{ std::move(stack) };

	BOOST_CHECK_EQUAL(newStack.pop(),4);
	BOOST_CHECK_EQUAL(newStack.pop(),3);
	BOOST_CHECK_EQUAL(newStack.pop(),2);
	BOOST_CHECK_EQUAL(newStack.pop(),1);

	BOOST_CHECK_EQUAL(newStack.empty(), true);
}

BOOST_AUTO_TEST_CASE(Stack_MoveAssignmentTest)
{
	mpb::Stack<int> stack{};

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);

	mpb::Stack<int> newStack{};

	BOOST_CHECK_EQUAL(newStack.empty(), true);

	newStack = std::move(stack);

	BOOST_CHECK_EQUAL(newStack.pop(), 4);
	BOOST_CHECK_EQUAL(newStack.pop(), 3);
	BOOST_CHECK_EQUAL(newStack.pop(), 2);
	BOOST_CHECK_EQUAL(newStack.pop(), 1);
	BOOST_CHECK_EQUAL(newStack.empty(), true);
}


BOOST_AUTO_TEST_SUITE_END()
