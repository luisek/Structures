#include "List.hpp"
#include <gtest\gtest.h>

class ListFixture : public ::testing::Test
{
protected:
    void SetUp()
    {
    }
    void TearDown()
    {
    }

};

TEST_F(ListFixture, List_empty)
{
    mpb::List<int> myList;
    myList.push_back(10);

    ASSERT_EQ(10, myList.pop_back());
    
}

TEST_F(ListFixture, List_PushWithoutPop)
{
    mpb::List<int> myList;
    myList.push_back(10);
    myList.push_back(21);

    ASSERT_EQ(21, myList.pop_back());
    ASSERT_EQ(10, myList.pop_back());
}

TEST_F(ListFixture, List_FindElement)
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

TEST_F(ListFixture, List_Empty)
{
    mpb::List<int> myList;
    ASSERT_TRUE(myList.empty());
}

TEST_F(ListFixture, List_Count)
{
    mpb::List<int> myList;

    for (auto i = 0; i < 100; ++i)
    {
        myList.push_back(i + 1);
    }
    ASSERT_EQ(100, myList.countElements());
}

TEST_F(ListFixture, List_CreateAndPopElements)
{
    mpb::List<int> list{ { 10,15,20,25,30 } };

    ASSERT_EQ(30, list.pop_back());
    ASSERT_EQ(25, list.pop_back());
    ASSERT_EQ(20, list.pop_back());
    ASSERT_EQ(15, list.pop_back());
    ASSERT_EQ(10, list.pop_back());
}

TEST_F(ListFixture, List_CopyList)
{
    mpb::List<int> list{ { 10,15,20,25,30 } };
    mpb::List<int> newList(list);

    ASSERT_EQ(30, list.pop_back());
    ASSERT_EQ(25, list.pop_back());
    ASSERT_EQ(20, list.pop_back());
    ASSERT_EQ(15, list.pop_back());
    ASSERT_EQ(10, list.pop_back());

    ASSERT_EQ(30, newList.pop_back());
    ASSERT_EQ(25, newList.pop_back());
    ASSERT_EQ(20, newList.pop_back());
    ASSERT_EQ(15, newList.pop_back());
    ASSERT_EQ(10, newList.pop_back());
}

TEST_F(ListFixture, List_CopyList_CopyAssignment)
{
    mpb::List<int> list{ { 10,15,20,25,30 } };
    mpb::List<int> newList;
    newList = list;

    ASSERT_EQ(30, list.pop_back());
    ASSERT_EQ(25, list.pop_back());
    ASSERT_EQ(20, list.pop_back());
    ASSERT_EQ(15, list.pop_back());
    ASSERT_EQ(10, list.pop_back());

    ASSERT_EQ(30, newList.pop_back());
    ASSERT_EQ(25, newList.pop_back());
    ASSERT_EQ(20, newList.pop_back());
    ASSERT_EQ(15, newList.pop_back());
    ASSERT_EQ(10, newList.pop_back());
}

TEST_F(ListFixture, List_MoveList)
{
    mpb::List<int> list{ { 10,15,20,25,30 } };
    mpb::List<int> newList(std::move(list));

    ASSERT_EQ(30, newList.pop_back());
    ASSERT_EQ(25, newList.pop_back());
    ASSERT_EQ(20, newList.pop_back());
    ASSERT_EQ(15, newList.pop_back());
    ASSERT_EQ(10, newList.pop_back());
}

TEST_F(ListFixture, List_ListMoveAssignment)
{
    mpb::List<int> list{ { 10,15,20,25,30 } };
    mpb::List<int> newList;

    newList = std::move(list);

    ASSERT_EQ(30, newList.pop_back());
    ASSERT_EQ(25, newList.pop_back());
    ASSERT_EQ(20, newList.pop_back());
    ASSERT_EQ(15, newList.pop_back());
    ASSERT_EQ(10, newList.pop_back());
}

TEST_F(ListFixture, List_pushFront)
{
    mpb::List<int> list{ { 10,15,20,25,30 } };

    list.push_front(1);

    ASSERT_EQ(30, list.pop_back());
    ASSERT_EQ(25, list.pop_back());
    ASSERT_EQ(20, list.pop_back());
    ASSERT_EQ(15, list.pop_back());
    ASSERT_EQ(10, list.pop_back());
    ASSERT_EQ(1, list.pop_back());
}

TEST_F(ListFixture, List_pushFrontOneElement)
{
    mpb::List<int> list{};

    list.push_front(1);
    ASSERT_EQ(1, list.pop_back());
}

TEST_F(ListFixture, List_popBackFromEmpty)
{
    mpb::List<int> list{};

    ASSERT_EQ(true, list.empty());
    ASSERT_THROW(list.pop_back(), mpb::ListException);
}

TEST_F(ListFixture, List_popFrontFromEmpty)
{
    mpb::List<int> list{};

    ASSERT_EQ(true, list.empty());
    ASSERT_THROW(list.pop_front(), mpb::ListException);
}

TEST_F(ListFixture, List_popFront)
{
    mpb::List<int> list{ { 10,15,20,25,30 } };

    ASSERT_EQ(10, list.pop_front());
    ASSERT_EQ(15, list.pop_front());
    ASSERT_EQ(20, list.pop_front());
    ASSERT_EQ(25, list.pop_front());
    ASSERT_EQ(30, list.pop_front());
    ASSERT_EQ(true, list.empty());
}

TEST_F(ListFixture, List_pushFrontOneElementAndPopFront)
{
    mpb::List<int> list;

    list.push_front(30);
    ASSERT_EQ(30, list.pop_front());
    ASSERT_EQ(true, list.empty());
}
