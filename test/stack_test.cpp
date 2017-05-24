#include "Stack.hpp"
#include <gtest/gtest.h>

class StackFixture : public ::testing::Test
{
protected:
    void SetUp()
    {
    }
    void TearDown()
    {
    }
};

TEST_F(StackFixture, Stack_CreateAndPopElements)
{
	mpb::Stack<int> stack;
    stack.push(10);
    stack.push(15);
    stack.push(20);
    stack.push(25);
    stack.push(30);
    ASSERT_EQ(stack.pop(), 30);
	ASSERT_EQ(stack.pop(), 25);
	ASSERT_EQ(stack.pop(), 20);
	ASSERT_EQ(stack.pop(), 15);
	ASSERT_EQ(stack.pop(), 10);
}

TEST_F(StackFixture, Stack_CreateEmptyAndCheckIt)
{
	mpb::Stack<int> stack;
    ASSERT_TRUE(stack.empty());
}

TEST_F(StackFixture, Stack_CreateEmptyPushAndCheck)
{
	mpb::Stack<int> stack;
    ASSERT_TRUE(stack.empty());
    stack.push(1);
    ASSERT_FALSE(stack.empty());
}

TEST_F(StackFixture, Stack_CreateEmptyAndPush)
{
	mpb::Stack<int> stack;
    for(auto i = 0; i < 10000; ++i)
        stack.push(i);
    
    for(auto i = 10000 - 1; i == 0; --i)
        ASSERT_EQ(stack.pop(), i);
    
}