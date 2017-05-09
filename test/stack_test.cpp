#include "Stack.hpp"
#include <gtest\gtest.h>

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
	mpb::Stack<int> stack{{10,15,20,25,30}};
    ASSERT_EQ(stack.pop(), 30);
	ASSERT_EQ(stack.pop(), 25);
	ASSERT_EQ(stack.pop(), 20);
	ASSERT_EQ(stack.pop(), 15);
	ASSERT_EQ(stack.pop(), 10);
}

TEST_F(StackFixture, Stack_CreateAndCheckEmpty)
{
	mpb::Stack<int> stack{};
	ASSERT_EQ(stack.empty(), true);
}

TEST_F(StackFixture, Stack_CreateEmpty_PopFromEmpty)
{
	mpb::Stack<int> stack{};
	ASSERT_EQ(stack.empty(), true);
	ASSERT_THROW(stack.pop(), mpb::StackException);
}

TEST_F(StackFixture, Stack_CreateAndPush)
{
	mpb::Stack<int> stack{};
	stack.push(10);
	stack.push(20);
	ASSERT_EQ(stack.empty(), false);
	ASSERT_EQ(stack.pop(), 20);
	ASSERT_EQ(stack.pop(), 10);
}


TEST_F(StackFixture, Stack_CreateAndPushMoreThan10Elements)
{
	mpb::Stack<int> stack{};
	for (auto i = 0; i < 12; ++i)
	{
		stack.push(i + 1);
	}
	ASSERT_EQ(stack.empty(), false);

	for (auto i = 0; i < 12; ++i)
	{
		ASSERT_EQ(stack.pop(), 12 - i);
	}
	ASSERT_EQ(stack.empty(), true);

}

TEST_F(StackFixture, Stack_CreateBigStack_InitializerListExcept)
{
	ASSERT_THROW(mpb::Stack<int> stack({1,2,3,4,5,6,7,8,9,10,11,12,13}), mpb::StackException);
}

TEST_F(StackFixture, Stack_CreateBigStack_InitializerList)
{
	mpb::Stack<int> stack({ 1,2,3,4,5,6,7,8,9,10,11,12,13 }, 13);
	for (auto i = 0; i < 13; ++i)
	{
		ASSERT_EQ(stack.pop(), 13 - i);
	}
}

TEST_F(StackFixture, Stack_CreateBigStack)
{
	mpb::Stack<int> stack{};
	for (auto i = 0; i < 10056; ++i)
	{
		stack.push(i);
	}
	ASSERT_EQ(stack.pop(), 10055);
	ASSERT_EQ(stack.pop(), 10054);
	ASSERT_EQ(stack.pop(), 10053);

	stack.push(10);
	ASSERT_EQ(stack.pop(), 10);
	ASSERT_EQ(stack.empty(), false);
}

TEST_F(StackFixture, Stack_CopyCtorTest)
{
	mpb::Stack<int> stack{};
	
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);

	mpb::Stack<int> newStack{ stack };

	ASSERT_EQ(stack.pop(), newStack.pop());
	ASSERT_EQ(stack.pop(), newStack.pop());
	ASSERT_EQ(stack.pop(), newStack.pop());
	ASSERT_EQ(stack.pop(), newStack.pop());

	ASSERT_EQ(stack.empty(), true);
	ASSERT_EQ(newStack.empty(), true);
}

TEST_F(StackFixture, Stack_CopyAssignmentTest)
{
	mpb::Stack<int> stack{};

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);

	mpb::Stack<int> newStack{};

	ASSERT_EQ(newStack.empty(), true);

	newStack = stack;

	ASSERT_EQ(stack.pop(), newStack.pop());
	ASSERT_EQ(stack.pop(), newStack.pop());
	ASSERT_EQ(stack.pop(), newStack.pop());
	ASSERT_EQ(stack.pop(), newStack.pop());

	ASSERT_EQ(stack.empty(), true);
	ASSERT_EQ(newStack.empty(), true);
}

TEST_F(StackFixture, Stack_MoveCtorTest)
{
	mpb::Stack<int> stack{};

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);

	mpb::Stack<int> newStack{ std::move(stack) };

	ASSERT_EQ(newStack.pop(),4);
	ASSERT_EQ(newStack.pop(),3);
	ASSERT_EQ(newStack.pop(),2);
	ASSERT_EQ(newStack.pop(),1);

	ASSERT_EQ(newStack.empty(), true);
}

TEST_F(StackFixture, Stack_MoveAssignmentTest)
{
	mpb::Stack<int> stack{};

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);

	mpb::Stack<int> newStack{};

	ASSERT_EQ(newStack.empty(), true);

	newStack = std::move(stack);

	ASSERT_EQ(newStack.pop(), 4);
	ASSERT_EQ(newStack.pop(), 3);
	ASSERT_EQ(newStack.pop(), 2);
	ASSERT_EQ(newStack.pop(), 1);
	ASSERT_EQ(newStack.empty(), true);
}
