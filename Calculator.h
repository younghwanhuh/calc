#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
    Calculator() noexcept = default;
    explicit Calculator(double initial_value) noexcept;

    double value() const noexcept;
    void set_value(double new_value) noexcept;
    void clear() noexcept;

    double add(double operand) noexcept;
    double subtract(double operand) noexcept;
    double multiply(double operand) noexcept;
    double divide(double operand);

    static double add(double lhs, double rhs) noexcept;
    static double subtract(double lhs, double rhs) noexcept;
    static double multiply(double lhs, double rhs) noexcept;
    static double divide(double lhs, double rhs);

private:
    double value_{0.0};
};

#endif  // CALCULATOR_H
