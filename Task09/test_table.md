# Task 9 — Test table template

| Test | Input | Expected result | Actual result | Pass/Fail |
|---|---|---|---|---|
| Zero units | Previous 1000, current 1000 | 0 units; Rs 50.00 | Fill after execution | |
| 100 units | Use readings differing by 100 | 100 units; Rs 50.00 | Fill after execution | |
| 150 units | Use readings differing by 150 | 150 units; Rs 162.50 | Fill after execution | |
| 200 units | Use readings differing by 200 | 200 units; Rs 275.00 | Fill after execution | |
| 350 units | Use readings differing by 350 | 350 units; Rs 950.00 | Fill after execution | |
| Rollover | 65535 to 0 | 1 unit | Fill after execution | |
| Invalid letters | `abc 10` | Reject input | Fill after execution | |
| Invalid decrease | 1000 to 500 | Reject input | Fill after execution | |

Note: the starter implementation handles a decrease as rollover only when the previous reading is within 1000 counts of the maximum. Align this policy with the exact meter specification and document it.
