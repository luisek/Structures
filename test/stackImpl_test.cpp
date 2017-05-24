#include "Stack_impl.hpp"
#include <gtest/gtest.h>

class StackImplFixture : public ::testing::Test
{
protected:
    void SetUp()
    {
    }
    void TearDown()
    {
    }
};

TEST_F(StackImplFixture, Stack_CreateAndPopElements)
{
	mpb::StackImpl<int> stack{{10,15,20,25,30}};
    ASSERT_EQ(stack.pop(), 30);
	ASSERT_EQ(stack.pop(), 25);
	ASSERT_EQ(stack.pop(), 20);
	ASSERT_EQ(stack.pop(), 15);
	ASSERT_EQ(stack.pop(), 10);
}

TEST_F(StackImplFixture, Stack_CreateAndCheckEmpty)
{
	mpb::StackImpl<int> stack{};
	ASSERT_EQ(stack.empty(), true);
}

TEST_F(StackImplFixture, Stack_CreateEmpty_PopFromEmpty)
{
	mpb::StackImpl<int> stack{};
	ASSERT_EQ(stack.empty(), true);
	ASSERT_THROW(stack.pop(), mpb::StackException);
}

TEST_F(StackImplFixture, Stack_CreateAndPush)
{
	mpb::StackImpl<int> stack{};
	stack.push(10);
	stack.push(20);
	ASSERT_EQ(stack.empty(), false);
	ASSERT_EQ(stack.pop(), 20);
	ASSERT_EQ(stack.pop(), 10);
}


TEST_F(StackImplFixture, Stack_CreateAndPushMoreThan10Elements)
{
	mpb::StackImpl<int> stack{};
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

TEST_F(StackImplFixture, Stack_CreateBigStack_InitializerListExcept)
{
	ASSERT_THROW(mpb::StackImpl<int> stack({1,2,3,4,5,6,7,8,9,10,11,12,13}), mpb::StackException);
}

TEST_F(StackImplFixture, Stack_CreateBigStack_InitializerList)
{
	mpb::StackImpl<int> stack({ 1,2,3,4,5,6,7,8,9,10,11,12,13 }, 13);
	for (auto i = 0; i < 13; ++i)
	{
		ASSERT_EQ(stack.pop(), 13 - i);
	}
}

TEST_F(StackImplFixture, Stack_CreateBigStack)
{
	mpb::StackImpl<int> stack{};
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

TEST_F(StackImplFixture, Stack_CopyCtorTest)
{
	mpb::StackImpl<int> stack{};
	
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);

	mpb::StackImpl<int> newStack{ stack };

	ASSERT_EQ(stack.pop(), newStack.pop());
	ASSERT_EQ(stack.pop(), newStack.pop());
	ASSERT_EQ(stack.pop(), newStack.pop());
	ASSERT_EQ(stack.pop(), newStack.pop());

	ASSERT_EQ(stack.empty(), true);
	ASSERT_EQ(newStack.empty(), true);
}

TEST_F(StackImplFixture, Stack_CopyAssignmentTest)
{
	mpb::StackImpl<int> stack{};

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);

	mpb::StackImpl<int> newStack{};

	ASSERT_EQ(newStack.empty(), true);

	newStack = stack;

	ASSERT_EQ(stack.pop(), newStack.pop());
	ASSERT_EQ(stack.pop(), newStack.pop());
	ASSERT_EQ(stack.pop(), newStack.pop());
	ASSERT_EQ(stack.pop(), newStack.pop());

	ASSERT_EQ(stack.empty(), true);
	ASSERT_EQ(newStack.empty(), true);
}

TEST_F(StackImplFixture, Stack_MoveCtorTest)
{
	mpb::StackImpl<int> stack{};

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);

	mpb::StackImpl<int> newStack{ std::move(stack) };

	ASSERT_EQ(newStack.pop(),4);
	ASSERT_EQ(newStack.pop(),3);
	ASSERT_EQ(newStack.pop(),2);
	ASSERT_EQ(newStack.pop(),1);

	ASSERT_EQ(newStack.empty(), true);
}

TEST_F(StackImplFixture, Stack_MoveAssignmentTest)
{
	mpb::StackImpl<int> stack{};

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);

	mpb::StackImpl<int> newStack{};

	ASSERT_EQ(newStack.empty(), true);

	newStack = std::move(stack);

	ASSERT_EQ(newStack.pop(), 4);
	ASSERT_EQ(newStack.pop(), 3);
	ASSERT_EQ(newStack.pop(), 2);
	ASSERT_EQ(newStack.pop(), 1);
	ASSERT_EQ(newStack.empty(), true);
}
