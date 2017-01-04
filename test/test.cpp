#define BOOST_TEST_MODULE StackTest
#include <boost/test/unit_test.hpp>

#include "stack.h"

BOOST_AUTO_TEST_SUITE(Stack)

BOOST_AUTO_TEST_CASE(Stack_CreateAndPopElement)
{
	//mpb::Stack stack{10};
    //BOOST_CHECK_EQUAL(stack.pop(), 10);
}
BOOST_AUTO_TEST_CASE(Stack_CreateAndCheckEmpty)
{
	/*mpb::Stack stack{ 10 };
	BOOST_CHECK_EQUAL(stack.empty(), false);*/
}

BOOST_AUTO_TEST_CASE(Stack_CreateAndPush)
{
	mpb::Stack stack{};
	stack.push(10);
	stack.push(20);
	BOOST_CHECK_EQUAL(stack.pop(), 20);
	BOOST_CHECK_EQUAL(stack.pop(), 10);

	BOOST_CHECK_EQUAL(stack.empty(), false);

}

BOOST_AUTO_TEST_SUITE_END()