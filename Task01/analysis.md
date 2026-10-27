# Task 1 — Problem analysis and data identification

| Data item | Purpose | Suggested representation |
|---|---|---|
| Household number | Identifies the account | `unsigned long` or validated string |
| Category | Selects applicable tariff | `char` or enum |
| Previous reading | Starting meter value | `meter_t` |
| Current reading | Ending meter value | `meter_t` |
| Units consumed | Difference, including rollover | `unsigned int` |
| Rate/slab boundaries | Tariff rules | Named constants |
| Energy charge | Slab-based cost | `long long` paise |
| Fixed charge | Charge independent of units | `long long` paise |
| Total bill | Fixed plus energy charge | `long long` paise |

**Rules:** validate readings; consumption must not be negative; total = energy charge + fixed charge; use one consistent tariff schedule; print rupees with exactly two paise digits. Assumption: the 16-bit meter can roll over at most once between readings.

**Text alternative:** `"01530"` needs 6 bytes including `'\0'` for five digits, while an integer typically occupies 2 or 4 bytes depending on type/system. Converting or comparing text takes `O(d)` time for `d` digits; integer comparison takes `O(1)`. Text preserves leading zeros, but needs validation.
