#include "gtest/gtest.h"
#include "ArrayStack.h"

TEST(ArrayStackTest, PushAndPopInt) {
    ArrayStack<int> stack;
    stack.push(10);
    stack.push(20);
    ASSERT_EQ(stack.pop(), 20);
    ASSERT_EQ(stack.pop(), 10);
    ASSERT_TRUE(stack.isEmpty());
}

TEST(ArrayStackTest, PushAndPopDouble) {
    ArrayStack<double> stack;
    stack.push(3.14);
    stack.push(2.71);
    ASSERT_EQ(stack.pop(), 2.71);
    ASSERT_EQ(stack.pop(), 3.14);
    ASSERT_TRUE(stack.isEmpty());
}

TEST(ArrayStackTest, PushAndPopString) {
    ArrayStack<std::string> stack;
    stack.push("Hello");
    stack.push("World");
    ASSERT_EQ(stack.pop(), "World");
    ASSERT_EQ(stack.pop(), "Hello");
    ASSERT_TRUE(stack.isEmpty());
}

TEST(ArrayStackTest, PeekInt) {
    ArrayStack<int> stack;
    stack.push(5);
    ASSERT_EQ(stack.peek(), 5);
    ASSERT_FALSE(stack.isEmpty());
    ASSERT_EQ(stack.size(), 1);
}

TEST(ArrayStackTest, PeekString) {
    ArrayStack<std::string> stack;
    stack.push("Test");
    ASSERT_EQ(stack.peek(), "Test");
    ASSERT_FALSE(stack.isEmpty());
    ASSERT_EQ(stack.size(), 1);
}

TEST(ArrayStackTest, IsEmpty) {
    ArrayStack<int> stack;
    ASSERT_TRUE(stack.isEmpty());
    stack.push(1);
    ASSERT_FALSE(stack.isEmpty());
    stack.pop();
    ASSERT_TRUE(stack.isEmpty());
}

TEST(ArrayStackTest, PopFromEmptyStack) {
    ArrayStack<int> stack;
    ASSERT_THROW(stack.pop(), std::out_of_range);
}

TEST(ArrayStackTest, PeekFromEmptyStack) {
    ArrayStack<int> stack;
    ASSERT_THROW(stack.peek(), std::out_of_range);
}
