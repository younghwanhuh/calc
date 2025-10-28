# calc

## Overview
Lightweight calculator library demonstrating safe arithmetic operations and limit-aware behaviors.

## Components
- `AbstractCalculator`: common interface for calculator implementations.
- `Calculator`: basic arithmetic with accumulation.
- `LimitedCalculator`: clamps results between configurable minimum and maximum values.

## Building
```powershell
cmake -S . -B build
cmake --build build
```

## Usage
```cpp
#include "Calculator.h"

Calculator calc;
calc.set_value(10);
calc.add(5);      // 15
calc.multiply(2); // 30
```

Use `LimitedCalculator` when you need to enforce numeric bounds and avoid overflow-like behavior.
