#include "LimitedCalculator.h"

#include <cmath>
#include <stdexcept>

LimitedCalculator::LimitedCalculator(double min_value, double max_value) noexcept
    : min_{min_value}, max_{max_value} {
    normalize_limits();
    value_ = clamp(0.0);
}

void LimitedCalculator::set_limits(double min_value, double max_value) noexcept {
    min_ = min_value;
    max_ = max_value;
    normalize_limits();
    value_ = clamp(value_);
}

double LimitedCalculator::min_limit() const noexcept {
    return min_;
}

double LimitedCalculator::max_limit() const noexcept {
    return max_;
}

bool LimitedCalculator::within_limits(double candidate) const noexcept {
    return candidate >= min_ && candidate <= max_;
}

double LimitedCalculator::value() const noexcept {
    return value_;
}

void LimitedCalculator::set_value(double new_value) noexcept {
    value_ = clamp(new_value);
}

void LimitedCalculator::clear() noexcept {
    value_ = clamp(0.0);
}

double LimitedCalculator::add(double operand) noexcept {
    value_ = clamp(value_ + operand);
    return value_;
}

double LimitedCalculator::add(double first, double second, double third) noexcept {
    value_ = clamp(value_ + first + second + third);
    return value_;
}

double LimitedCalculator::add(double first, double second, double third, double fourth, double fifth) noexcept {
    value_ = clamp(value_ + first + second + third + fourth + fifth);
    return value_;
}

double LimitedCalculator::subtract(double operand) noexcept {
    value_ = clamp(value_ - operand);
    return value_;
}

double LimitedCalculator::multiply(double operand) noexcept {
    value_ = clamp(value_ * operand);
    return value_;
}

double LimitedCalculator::multiply(double first, double second, double third, double fourth) noexcept {
    value_ = clamp(value_ * first * second * third * fourth);
    return value_;
}

double LimitedCalculator::divide(double operand) {
    if (operand == 0.0) {
        throw std::invalid_argument("Division by zero is undefined.");
    }

    value_ = clamp(value_ / operand);
    return value_;
}

double LimitedCalculator::sqrt() {
    if (value_ < 0.0) {
        throw std::domain_error("Square root of a negative value is undefined.");
    }

    const double result = std::sqrt(value_);
    if (!within_limits(result)) {
        throw std::out_of_range("Square root result falls outside configured limits.");
    }

    value_ = result;
    return value_;
}

void LimitedCalculator::normalize_limits() noexcept {
    if (min_ > max_) {
        const double temp = min_;
        min_ = max_;
        max_ = temp;
    }
}

double LimitedCalculator::clamp(double candidate) const noexcept {
    if (candidate < min_) {
        return min_;
    }

    if (candidate > max_) {
        return max_;
    }

    return candidate;
}

