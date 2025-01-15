#include "../include/fibonacci.hpp"
#include <gtest/gtest.h>

TEST(FibonacciTest, CalculateCorrectly) {
    EXPECT_EQ(classic(0), 0);
    EXPECT_EQ(classic(1), 1);
    EXPECT_EQ(classic(2), 1);
    EXPECT_EQ(classic(3), 2);
    EXPECT_EQ(classic(4), 3);
    EXPECT_EQ(classic(5), 5);
    EXPECT_EQ(classic(10), 55);
}

TEST(FibonacciTest, NegativeInputReturnsZero) {
    EXPECT_EQ(classic(-1), 0);
    EXPECT_EQ(classic(-5), 0);
}

TEST(FibonacciTest, OptimizedCalculateCorrectly) {
    EXPECT_EQ(optimized(0), 0);
    EXPECT_EQ(optimized(1), 1);
    EXPECT_EQ(optimized(2), 1);
    EXPECT_EQ(optimized(3), 2);
    EXPECT_EQ(optimized(4), 3);
    EXPECT_EQ(optimized(5), 5);
    EXPECT_EQ(optimized(10), 55);
}

TEST(FibonacciTest, OptimizedNegativeInputReturnsZero) {
    EXPECT_EQ(optimized(-1), 0);
    EXPECT_EQ(optimized(-5), 0);
}
