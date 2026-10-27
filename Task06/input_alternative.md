# Task 6 — fgets and strtol alternative

A robust alternative reads one line using `fgets`, then parses it with `strtol`. Check that at least one digit was consumed, check `errno == ERANGE`, validate the allowed range, and ensure only whitespace remains after the number. Parsing a line of length `L` takes `O(L)` time and uses `O(L)` buffer space (or `O(B)` for a fixed buffer size `B`). Compared with `scanf`, line-based parsing makes it easier to discard an entire invalid line and continue cleanly.
