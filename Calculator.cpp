#include "Calculator.h"

#include <cmath>
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

double Calculator::add(double first, double second, double third) noexcept {
    value_ += first + second + third;
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

double Calculator::sqrt() {
    if (value_ < 0.0) {
        throw std::domain_error("Square root of a negative value is undefined.");
    }

    value_ = std::sqrt(value_);
    return value_;
}

double Calculator::add(double lhs, double rhs) noexcept {
    return lhs + rhs;
}

double Calculator::add(double first, double second, double third) noexcept {
    return first + second + third;
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


