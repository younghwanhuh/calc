#include <gtest/gtest.h>

#include "Calculator.h"
#include "LimitedCalculator.h"

TEST(CalculatorTest, DefaultValueIsZero) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.value(), 0.0);
}

TEST(CalculatorTest, ConstructorSetsInitialValue) {
    Calculator calc(42.5);
    EXPECT_DOUBLE_EQ(calc.value(), 42.5);
}

TEST(CalculatorTest, SetValueOverridesExistingValue) {
    Calculator calc;
    calc.set_value(-13.25);
    EXPECT_DOUBLE_EQ(calc.value(), -13.25);
}

TEST(CalculatorTest, ClearResetsValueToZero) {
    Calculator calc(10.0);
    calc.clear();
    EXPECT_DOUBLE_EQ(calc.value(), 0.0);
}

TEST(CalculatorTest, AddAccumulatesValue) {
    Calculator calc(5.0);
    EXPECT_DOUBLE_EQ(calc.add(3.0), 8.0);
    EXPECT_DOUBLE_EQ(calc.value(), 8.0);
}

TEST(CalculatorTest, AddThreeOperandsAccumulatesValue) {
    Calculator calc(1.0);
    EXPECT_DOUBLE_EQ(calc.add(1.0, 2.0, 3.0), 7.0);
    EXPECT_DOUBLE_EQ(calc.value(), 7.0);
}

TEST(CalculatorTest, AddFiveOperandsAccumulatesValue) {
    Calculator calc(0.5);
    EXPECT_DOUBLE_EQ(calc.add(1.0, 2.0, 3.0, 4.0, 5.0), 15.5);
    EXPECT_DOUBLE_EQ(calc.value(), 15.5);
}

TEST(CalculatorTest, SubtractDecreasesValue) {
    Calculator calc(7.0);
    EXPECT_DOUBLE_EQ(calc.subtract(2.5), 4.5);
    EXPECT_DOUBLE_EQ(calc.value(), 4.5);
}

TEST(CalculatorTest, MultiplyScalesValue) {
    Calculator calc(3.0);
    EXPECT_DOUBLE_EQ(calc.multiply(2.0), 6.0);
    EXPECT_DOUBLE_EQ(calc.value(), 6.0);
}

TEST(CalculatorTest, MultiplyFourOperandsScalesValue) {
    Calculator calc(2.0);
    EXPECT_DOUBLE_EQ(calc.multiply(2.0, 3.0, 4.0, 5.0), 240.0);
    EXPECT_DOUBLE_EQ(calc.value(), 240.0);
}

TEST(CalculatorTest, DivideThrowsOnZero) {
    Calculator calc(9.0);
    EXPECT_THROW(calc.divide(0.0), std::invalid_argument);
}

TEST(CalculatorTest, DivideUpdatesValue) {
    Calculator calc(9.0);
    EXPECT_DOUBLE_EQ(calc.divide(3.0), 3.0);
    EXPECT_DOUBLE_EQ(calc.value(), 3.0);
}

TEST(CalculatorTest, SqrtThrowsOnNegativeValue) {
    Calculator calc;
    calc.set_value(-4.0);
    EXPECT_THROW(calc.sqrt(), std::domain_error);
}

TEST(CalculatorTest, SqrtUpdatesValue) {
    Calculator calc;
    calc.set_value(49.0);
    EXPECT_DOUBLE_EQ(calc.sqrt(), 7.0);
    EXPECT_DOUBLE_EQ(calc.value(), 7.0);
}

TEST(CalculatorStaticsTest, AddHelpersReturnExpectedResults) {
    EXPECT_DOUBLE_EQ(Calculator::add(1.5, 2.5), 4.0);
    EXPECT_DOUBLE_EQ(Calculator::add_three(1.0, 2.0, 3.0), 6.0);
    EXPECT_DOUBLE_EQ(Calculator::add_five(1.0, 2.0, 3.0, 4.0, 5.0), 15.0);
}

TEST(CalculatorStaticsTest, MultiplyAndSubtractHelpersReturnExpectedResults) {
    EXPECT_DOUBLE_EQ(Calculator::subtract(10.0, 3.0), 7.0);
    EXPECT_DOUBLE_EQ(Calculator::multiply(2.0, 5.0), 10.0);
    EXPECT_DOUBLE_EQ(Calculator::multiply_four(1.0, 2.0, 3.0, 4.0), 24.0);
}

TEST(CalculatorStaticsTest, DivideHelperThrowsOnZero) {
    EXPECT_THROW(Calculator::divide(5.0, 0.0), std::invalid_argument);
}

TEST(CalculatorStaticsTest, DivideHelperReturnsQuotient) {
    EXPECT_DOUBLE_EQ(Calculator::divide(9.0, 3.0), 3.0);
}

TEST(LimitedCalculatorTest, DefaultLimitsClampInitialValue) {
    LimitedCalculator calc;
    EXPECT_DOUBLE_EQ(calc.min_limit(), -1000.0);
    EXPECT_DOUBLE_EQ(calc.max_limit(), 1000.0);
    EXPECT_DOUBLE_EQ(calc.value(), 0.0);
}

TEST(LimitedCalculatorTest, SetLimitsNormalizesValues) {
    LimitedCalculator calc;
    calc.set_limits(10.0, -10.0);
    EXPECT_DOUBLE_EQ(calc.min_limit(), -10.0);
    EXPECT_DOUBLE_EQ(calc.max_limit(), 10.0);
}

TEST(LimitedCalculatorTest, SetLimitsClampsCurrentValue) {
    LimitedCalculator calc;
    calc.set_value(500.0);
    calc.set_limits(-5.0, 5.0);
    EXPECT_DOUBLE_EQ(calc.value(), 5.0);
}

TEST(LimitedCalculatorTest, SetValueClampsToRange) {
    LimitedCalculator calc(-5.0, 5.0);
    calc.set_value(10.0);
    EXPECT_DOUBLE_EQ(calc.value(), 5.0);
    calc.set_value(-10.0);
    EXPECT_DOUBLE_EQ(calc.value(), -5.0);
}

TEST(LimitedCalculatorTest, ClearHonorsLowerBound) {
    LimitedCalculator calc(2.0, 10.0);
    calc.set_value(6.0);
    calc.clear();
    EXPECT_DOUBLE_EQ(calc.value(), 2.0);
}

TEST(LimitedCalculatorTest, AddClampsAtUpperBound) {
    LimitedCalculator calc(-5.0, 5.0);
    calc.set_value(4.0);
    EXPECT_DOUBLE_EQ(calc.add(4.0), 5.0);
}

TEST(LimitedCalculatorTest, AddOverloadsClampAtUpperBound) {
    LimitedCalculator calc(-5.0, 5.0);
    calc.set_value(1.0);
    EXPECT_DOUBLE_EQ(calc.add(2.0, 2.0, 2.0), 5.0);
    calc.clear();
    calc.set_value(1.0);
    EXPECT_DOUBLE_EQ(calc.add(2.0, 2.0, 2.0, 2.0, 2.0), 5.0);
}

TEST(LimitedCalculatorTest, SubtractClampsAtLowerBound) {
    LimitedCalculator calc(-5.0, 5.0);
    calc.set_value(-3.0);
    EXPECT_DOUBLE_EQ(calc.subtract(5.0), -5.0);
}

TEST(LimitedCalculatorTest, MultiplyClampsAtBounds) {
    LimitedCalculator calc(-5.0, 5.0);
    calc.set_value(2.0);
    EXPECT_DOUBLE_EQ(calc.multiply(4.0), 5.0);
    calc.set_value(-2.0);
    EXPECT_DOUBLE_EQ(calc.multiply(4.0), -5.0);
}

TEST(LimitedCalculatorTest, MultiplyFourOperandsClampsAtBounds) {
    LimitedCalculator calc(-5.0, 5.0);
    calc.set_value(1.0);
    EXPECT_DOUBLE_EQ(calc.multiply(2.0, 2.0, 2.0, 2.0), 5.0);
}

TEST(LimitedCalculatorTest, DivideThrowsOnZero) {
    LimitedCalculator calc;
    EXPECT_THROW(calc.divide(0.0), std::invalid_argument);
}

TEST(LimitedCalculatorTest, DivideClampsToBounds) {
    LimitedCalculator calc(-5.0, 5.0);
    calc.set_value(5.0);
    EXPECT_DOUBLE_EQ(calc.divide(0.5), 5.0);
}

TEST(LimitedCalculatorTest, SqrtThrowsOnNegativeValue) {
    LimitedCalculator calc;
    calc.set_value(-4.0);
    EXPECT_THROW(calc.sqrt(), std::domain_error);
}

TEST(LimitedCalculatorTest, SqrtThrowsWhenResultOutOfLimits) {
    LimitedCalculator calc(5.0, 6.0);
    calc.set_value(6.0);
    EXPECT_THROW(calc.sqrt(), std::out_of_range);
}

TEST(LimitedCalculatorTest, SqrtSucceedsWithinLimits) {
    LimitedCalculator calc(0.0, 10.0);
    calc.set_value(9.0);
    EXPECT_DOUBLE_EQ(calc.sqrt(), 3.0);
    EXPECT_DOUBLE_EQ(calc.value(), 3.0);
}

TEST(LimitedCalculatorTest, WithinLimitsReportsCorrectly) {
    LimitedCalculator calc(-2.0, 2.0);
    EXPECT_TRUE(calc.within_limits(0.0));
    EXPECT_FALSE(calc.within_limits(3.0));
    EXPECT_FALSE(calc.within_limits(-3.0));
}

