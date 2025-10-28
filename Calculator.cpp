#include "Calculator.h"

#include <stdexcept>

Calculator::Calculator(double initial_value) noexcept : value_{initial_value} {}

double Calculator::value() const noexcept {
    return value_;
}

void Calculator::set_value(double new_value) noexcept {
    value_ = new_value;
}

void Calculator::clear() noexcept {
    value_ = 0.0;
}

double Calculator::add(double operand) noexcept {
    value_ += operand;
    return value_;
}

double Calculator::subtract(double operand) noexcept {
    value_ -= operand;
    return value_;
}

double Calculator::multiply(double operand) noexcept {
    value_ *= operand;
    return value_;
}

double Calculator::divide(double operand) {
    if (operand == 0.0) {
        throw std::invalid_argument("Division by zero is undefined.");
    }

    value_ /= operand;
    return value_;
}

double Calculator::add(double lhs, double rhs) noexcept {
    return lhs + rhs;
}

double Calculator::subtract(double lhs, double rhs) noexcept {
    return lhs - rhs;
}

double Calculator::multiply(double lhs, double rhs) noexcept {
    return lhs * rhs;
}

double Calculator::divide(double lhs, double rhs) {
    if (rhs == 0.0) {
        throw std::invalid_argument("Division by zero is undefined.");
    }

    return lhs / rhs;
}
