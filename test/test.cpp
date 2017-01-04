#define BOOST_TEST_MODULE StackTest
#include <boost/test/unit_test.hpp>

#include "stack.h"

BOOST_AUTO_TEST_SUITE(Stack)

BOOST_AUTO_TEST_CASE(Stack_CreateAndPopElements)
{
	mpb::Stack stack{{10,15,20,25,30}};
    BOOST_CHECK_EQUAL(stack.pop(), 30);
	BOOST_CHECK_EQUAL(stack.pop(), 25);
	BOOST_CHECK_EQUAL(stack.pop(), 20);
	BOOST_CHECK_EQUAL(stack.pop(), 15);
	BOOST_CHECK_EQUAL(stack.pop(), 10);
}

BOOST_AUTO_TEST_CASE(Stack_CreateAndCheckEmpty)
{
	mpb::Stack stack{};
	BOOST_CHECK_EQUAL(stack.empty(), true);
}

BOOST_AUTO_TEST_CASE(Stack_CreateEmpty_PopFromEmpty)
{
	mpb::Stack stack{};
	BOOST_CHECK_EQUAL(stack.empty(), true);
	BOOST_CHECK_THROW(stack.pop(), mpb::StackException);
}

BOOST_AUTO_TEST_CASE(Stack_CreateAndPush)
{
	mpb::Stack stack{};
	stack.push(10);
	stack.push(20);
	BOOST_CHECK_EQUAL(stack.empty(), false);
	BOOST_CHECK_EQUAL(stack.pop(), 20);
	BOOST_CHECK_EQUAL(stack.pop(), 10);
}


BOOST_AUTO_TEST_CASE(Stack_CreateAndPushMoreThan10Elements)
{
	mpb::Stack stack{};
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.push(6);
	stack.push(7);
	stack.push(8);
	stack.push(9);
	stack.push(10);
	stack.push(11);
	stack.push(12);

	BOOST_CHECK_EQUAL(stack.empty(), false);
	BOOST_CHECK_EQUAL(stack.pop(), 12);
	BOOST_CHECK_EQUAL(stack.pop(), 11);
	BOOST_CHECK_EQUAL(stack.pop(), 10);
	BOOST_CHECK_EQUAL(stack.pop(), 9);
	BOOST_CHECK_EQUAL(stack.pop(), 8);
	BOOST_CHECK_EQUAL(stack.pop(), 7);
	BOOST_CHECK_EQUAL(stack.pop(), 6);
	BOOST_CHECK_EQUAL(stack.pop(), 5);
	BOOST_CHECK_EQUAL(stack.pop(), 4);
	BOOST_CHECK_EQUAL(stack.pop(), 3);
	BOOST_CHECK_EQUAL(stack.pop(), 2);
	BOOST_CHECK_EQUAL(stack.pop(), 1);
	BOOST_CHECK_EQUAL(stack.empty(), true);

}

BOOST_AUTO_TEST_CASE(Stack_CreateBigStack_InitializerListExcept)
{
	BOOST_CHECK_THROW(mpb::Stack stack({1,2,3,4,5,6,7,8,9,10,11,12,13}), mpb::StackException);
}

BOOST_AUTO_TEST_CASE(Stack_CreateBigStack_InitializerList)
{
	mpb::Stack stack({ 1,2,3,4,5,6,7,8,9,10,11,12,13 }, 13);
	for (auto i = 0; i < 13; ++i)
	{
		BOOST_CHECK_EQUAL(stack.pop(), 13 - i);
	}
}

BOOST_AUTO_TEST_SUITE_END()