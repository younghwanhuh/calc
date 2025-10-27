#ifndef LIMITED_CALCULATOR_H
#define LIMITED_CALCULATOR_H

#include "AbstractCalculator.h"

class LimitedCalculator : public AbstractCalculator {
public:
    explicit LimitedCalculator(double min_value = -1000.0, double max_value = 1000.0) noexcept;

    void set_limits(double min_value, double max_value) noexcept;
    double min_limit() const noexcept;
    double max_limit() const noexcept;
    bool within_limits(double candidate) const noexcept;

    double value() const noexcept override;
    void set_value(double new_value) noexcept override;
    void clear() noexcept override;

    double add(double operand) noexcept override;
    double subtract(double operand) noexcept override;
    double multiply(double operand) noexcept override;
    double divide(double operand) override;

private:
    void normalize_limits() noexcept;
    double clamp(double candidate) const noexcept;

    double value_{0.0};
    double min_;
    double max_;
};

#endif  // LIMITED_CALCULATOR_H
