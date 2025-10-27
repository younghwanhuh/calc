#include "LimitedCalculator.h"

#include <stdexcept>

LimitedCalculator::LimitedCalculator(double min_value, double max_value) noexcept
    : min_{min_value}, max_{max_value} {
    if (min_ > max_) {
        const double temp = min_;
        min_ = max_;
        max_ = temp;
    }

    value_ = clamp(0.0);
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

double LimitedCalculator::subtract(double operand) noexcept {
    value_ = clamp(value_ - operand);
    return value_;
}

double LimitedCalculator::multiply(double operand) noexcept {
    value_ = clamp(value_ * operand);
    return value_;
}

double LimitedCalculator::divide(double operand) {
    if (operand == 0.0) {
        throw std::invalid_argument("Division by zero is undefined.");
    }

    value_ = clamp(value_ / operand);
    return value_;
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
