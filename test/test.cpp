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
	BOOST_CHECK_EQUAL(stack.empty(), true);
	stack.push(10);
	stack.push(20);
	BOOST_CHECK_EQUAL(stack.empty(), false);
	BOOST_CHECK_EQUAL(stack.pop(), 20);
	BOOST_CHECK_EQUAL(stack.pop(), 10);
}

BOOST_AUTO_TEST_SUITE_END()