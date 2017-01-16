#include <boost/test/unit_test.hpp>
#include "List.hpp"

BOOST_AUTO_TEST_SUITE(List)

BOOST_AUTO_TEST_CASE(List_empty)
{
    mpb::List myList;
    myList.push_back(10);
	
	BOOST_CHECK_EQUAL(10, myList.pop_back());
}

BOOST_AUTO_TEST_CASE(List_PushWithoutPop)
{
	mpb::List myList;
	myList.push_back(10);
	myList.push_back(21);

	BOOST_CHECK_EQUAL(21, myList.pop_back());
	BOOST_CHECK_EQUAL(10, myList.pop_back());
}

BOOST_AUTO_TEST_SUITE_END()
