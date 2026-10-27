# Task 10 — Expected versus actual execution

Run experiments with 4,000, 60,000 and 800,000 bills. Use the same bill amounts for both versions. For integer paise:
```c
long long total_paise = 0;
for (int i = 0; i < n; ++i) total_paise += bill_paise;
```
For floating point, accumulate the rupee amount and compare after applying the documented rounding rule. Record the exact test bill values and results. Do not invent a measurement: the outcome depends on the input values and rounding method.

| Number of bills | Integer-paise total | Floating-point total | Difference |
|---:|---:|---:|---:|
| 4,000 | Fill after run | Fill after run | Fill after run |
| 60,000 | Fill after run | Fill after run | Fill after run |
| 800,000 | Fill after run | Fill after run | Fill after run |

Check `sizeof(int)`, `sizeof(long)`, `sizeof(long long)`, `INT_MAX`, `LONG_MAX`, `LLONG_MAX`, `FLT_DIG`, and `DBL_DIG` on your system. Integer addition and double addition are both `O(1)` per value. Integer totals fail by overflow if the limit is exceeded; double totals may retain range but lose exact low-order precision.
