# Task 4 — Macro and inline comparison

For a fixed arithmetic expression, evaluation is `O(1)` for both a macro and a function. A macro expands source text at each use, potentially increasing generated code size as the number of uses `k` grows. A `static inline` function is type-checked and evaluates each argument once; the compiler may inline it or emit a function body. Avoid passing expressions with side effects to macros such as `MAX(i++, j)`.
