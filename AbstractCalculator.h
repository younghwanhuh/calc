#ifndef ABSTRACT_CALCULATOR_H
#define ABSTRACT_CALCULATOR_H

class AbstractCalculator {
public:
    virtual ~AbstractCalculator() = default;

    virtual double value() const noexcept = 0;
    virtual void set_value(double new_value) noexcept = 0;
    virtual void clear() noexcept = 0;

    virtual double add(double operand) noexcept = 0;
    virtual double subtract(double operand) noexcept = 0;
    virtual double multiply(double operand) noexcept = 0;
    virtual double divide(double operand) = 0;
    virtual double sqrt() = 0;
};

#endif  // ABSTRACT_CALCULATOR_H
