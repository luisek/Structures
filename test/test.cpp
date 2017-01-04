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
	BOOST_CHECK_THROW(stack.pop(), mpb::EmptyStackException);
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

BOOST_AUTO_TEST_SUITE_END()