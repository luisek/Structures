#include <boost/test/unit_test.hpp>
#include "List.hpp"

BOOST_AUTO_TEST_SUITE(List)

BOOST_AUTO_TEST_CASE(List_empty)
{
    mpb::List<int> myList;
    myList.push_back(10);
	
	BOOST_CHECK_EQUAL(10, myList.pop_back());
}

BOOST_AUTO_TEST_CASE(List_PushWithoutPop)
{
	mpb::List<int> myList;
	myList.push_back(10);
	myList.push_back(21);

	BOOST_CHECK_EQUAL(21, myList.pop_back());
	BOOST_CHECK_EQUAL(10, myList.pop_back());
}

BOOST_AUTO_TEST_CASE(List_FindElement)
{
	//mpb::List<int> myList;

	//for (auto i = 0; i < 10; ++i)
	//{
	//	myList.push_back(i);
	//}
	//mpb::List<int>::Node<int>* tmp = myList.find(8);
	//BOOST_CHECK(tmp != nullptr);
	//BOOST_CHECK_EQUAL( 8, tmp->value);
	//BOOST_CHECK(!myList.empty());
}

BOOST_AUTO_TEST_CASE(List_Empty)
{
	mpb::List<int> myList;
	BOOST_CHECK(myList.empty());
}

BOOST_AUTO_TEST_CASE(List_Count)
{
	mpb::List<int> myList;

	for (auto i = 0; i < 100; ++i)
	{
		myList.push_back(i + 1);
	}
	BOOST_CHECK_EQUAL(100, myList.countElements());
}

BOOST_AUTO_TEST_CASE(List_CreateAndPopElements)
{
	mpb::List<int> list{ { 10,15,20,25,30 } };
	
	BOOST_CHECK_EQUAL(30, list.pop_back());
	BOOST_CHECK_EQUAL(25, list.pop_back());
	BOOST_CHECK_EQUAL(20, list.pop_back());
	BOOST_CHECK_EQUAL(15, list.pop_back());
	BOOST_CHECK_EQUAL(10, list.pop_back());
}

BOOST_AUTO_TEST_CASE(List_CopyList)
{
	mpb::List<int> list{ { 10,15,20,25,30 } };
	mpb::List<int> newList(list);

	BOOST_CHECK_EQUAL(30, list.pop_back());
	BOOST_CHECK_EQUAL(25, list.pop_back());
	BOOST_CHECK_EQUAL(20, list.pop_back());
	BOOST_CHECK_EQUAL(15, list.pop_back());
	BOOST_CHECK_EQUAL(10, list.pop_back());

	BOOST_CHECK_EQUAL(30, newList.pop_back());
	BOOST_CHECK_EQUAL(25, newList.pop_back());
	BOOST_CHECK_EQUAL(20, newList.pop_back());
	BOOST_CHECK_EQUAL(15, newList.pop_back());
	BOOST_CHECK_EQUAL(10, newList.pop_back());
}

BOOST_AUTO_TEST_CASE(List_CopyList_CopyAssignment)
{
	mpb::List<int> list{ { 10,15,20,25,30 } };
	mpb::List<int> newList;
	newList = list;

	BOOST_CHECK_EQUAL(30, list.pop_back());
	BOOST_CHECK_EQUAL(25, list.pop_back());
	BOOST_CHECK_EQUAL(20, list.pop_back());
	BOOST_CHECK_EQUAL(15, list.pop_back());
	BOOST_CHECK_EQUAL(10, list.pop_back());

	BOOST_CHECK_EQUAL(30, newList.pop_back());
	BOOST_CHECK_EQUAL(25, newList.pop_back());
	BOOST_CHECK_EQUAL(20, newList.pop_back());
	BOOST_CHECK_EQUAL(15, newList.pop_back());
	BOOST_CHECK_EQUAL(10, newList.pop_back());
}

BOOST_AUTO_TEST_CASE(List_MoveList)
{
	mpb::List<int> list{ { 10,15,20,25,30 } };
	mpb::List<int> newList(std::move(list));

	BOOST_CHECK_EQUAL(30, newList.pop_back());
	BOOST_CHECK_EQUAL(25, newList.pop_back());
	BOOST_CHECK_EQUAL(20, newList.pop_back());
	BOOST_CHECK_EQUAL(15, newList.pop_back());
	BOOST_CHECK_EQUAL(10, newList.pop_back());
}

BOOST_AUTO_TEST_CASE(List_ListMoveAssignment)
{
	mpb::List<int> list{ { 10,15,20,25,30 } };
	mpb::List<int> newList;

	newList = std::move(list);

	BOOST_CHECK_EQUAL(30, newList.pop_back());
	BOOST_CHECK_EQUAL(25, newList.pop_back());
	BOOST_CHECK_EQUAL(20, newList.pop_back());
	BOOST_CHECK_EQUAL(15, newList.pop_back());
	BOOST_CHECK_EQUAL(10, newList.pop_back());
}

BOOST_AUTO_TEST_CASE(List_pushFront)
{
	mpb::List<int> list{ { 10,15,20,25,30 } };
	
	list.push_front(1);

	BOOST_CHECK_EQUAL(30, list.pop_back());
	BOOST_CHECK_EQUAL(25, list.pop_back());
	BOOST_CHECK_EQUAL(20, list.pop_back());
	BOOST_CHECK_EQUAL(15, list.pop_back());
	BOOST_CHECK_EQUAL(10, list.pop_back());
	BOOST_CHECK_EQUAL(1, list.pop_back());
}

BOOST_AUTO_TEST_CASE(List_pushFrontOneElement)
{
	mpb::List<int> list{};

	list.push_front(1);
	BOOST_CHECK_EQUAL(1, list.pop_back());
}

BOOST_AUTO_TEST_CASE(List_popBackFromEmpty)
{
	mpb::List<int> list{};

	BOOST_CHECK_EQUAL(true, list.empty());
    BOOST_CHECK_THROW(list.pop_back(), mpb::ListException);
}

BOOST_AUTO_TEST_CASE(List_popFrontFromEmpty)
{
    mpb::List<int> list{};

    BOOST_CHECK_EQUAL(true, list.empty());
    BOOST_CHECK_THROW(list.pop_front(), mpb::ListException);
}

BOOST_AUTO_TEST_CASE(List_popFront)
{
	mpb::List<int> list{ { 10,15,20,25,30 } };

	BOOST_CHECK_EQUAL(10, list.pop_front());
	BOOST_CHECK_EQUAL(15, list.pop_front());
	BOOST_CHECK_EQUAL(20, list.pop_front());
	BOOST_CHECK_EQUAL(25, list.pop_front());
	BOOST_CHECK_EQUAL(30, list.pop_front());
	BOOST_CHECK_EQUAL(true, list.empty());
}

BOOST_AUTO_TEST_CASE(List_pushFrontOneElementAndPopFront)
{
    mpb::List<int> list;

    list.push_front(30);
    BOOST_CHECK_EQUAL(30, list.pop_front());
    BOOST_CHECK_EQUAL(true, list.empty());
}

BOOST_AUTO_TEST_SUITE_END()
