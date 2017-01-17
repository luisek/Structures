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

BOOST_AUTO_TEST_CASE(List_FindElement)
{
	mpb::List myList;

	for (auto i = 0; i < 10; ++i)
	{
		myList.push_back(i);
	}
	mpb::List::Node* tmp = myList.find(8);
	BOOST_CHECK(tmp != nullptr);
	BOOST_CHECK_EQUAL( 8, tmp->value);
	BOOST_CHECK(!myList.empty());
}

BOOST_AUTO_TEST_CASE(List_Empty)
{
	mpb::List myList;
	BOOST_CHECK(myList.empty());
}

BOOST_AUTO_TEST_CASE(List_Count)
{
	mpb::List myList;

	for (auto i = 0; i < 100; ++i)
	{
		myList.push_back(i + 1);
	}
	BOOST_CHECK_EQUAL(100, myList.countElements());
}

BOOST_AUTO_TEST_SUITE_END()
