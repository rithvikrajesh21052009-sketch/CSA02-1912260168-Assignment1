# Task 11 — Final design recommendation

1. Use a dedicated unsigned type for the meter register and validate the range before calculating consumption.
2. Use integer paise for fixed charge, slab charge and bill totals.
3. Use `long long` for aggregate monetary totals, after calculating worst-case totals and checking `LLONG_MAX`.
4. Keep tariff definitions in one central location for the original fixed-tariff version.
5. Use include guards in headers and prototypes for shared functions.
6. Use `#ifdef DEBUG` for optional diagnostic output.
7. Reject malformed, negative and out-of-range input.
8. Document exactly when a lower current reading counts as rollover.
9. Test normal, boundary, rollover and invalid-input cases.
10. For tariff changes that must not require recompilation, read and validate tariff settings from a configuration file at program startup.

A configuration file with `t` values requires `O(t)` parsing time and `O(t)` storage. It avoids rebuilding the executable for every rate revision, but introduces configuration validation and file-error handling.
