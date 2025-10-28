#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "AbstractCalculator.h"

class Calculator : public AbstractCalculator {
public:
    Calculator() noexcept = default;
    explicit Calculator(double initial_value) noexcept;

    double value() const noexcept override;
    void set_value(double new_value) noexcept override;
    void clear() noexcept override;

    double add(double operand) noexcept override;
    double subtract(double operand) noexcept override;
    double multiply(double operand) noexcept override;
    double multiply(double first, double second, double third, double fourth) noexcept override;
    double divide(double operand) override;
    double sqrt() override;
    double add(double first, double second, double third) noexcept override;
    double add(double first, double second, double third, double fourth, double fifth) noexcept override;

    static double add(double lhs, double rhs) noexcept;
    static double add_three(double first, double second, double third) noexcept;
    static double add_five(double first, double second, double third, double fourth, double fifth) noexcept;
    static double multiply_four(double first, double second, double third, double fourth) noexcept;
    static double subtract(double lhs, double rhs) noexcept;
    static double multiply(double lhs, double rhs) noexcept;
    static double divide(double lhs, double rhs);

private:
    double value_{0.0};
};

#endif  // CALCULATOR_H
