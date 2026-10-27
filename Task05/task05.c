#include <stdio.h>
#include "billing.h"

long compute_bill(int units)
{
    long paise = FIXED_CHARGE_PAISE;
    if (units < 0) return -1L;
    if (units > SLAB2_UNITS)
        paise += (long)(units - SLAB2_UNITS) * RATE3_PAISE;
    if (units > SLAB1_UNITS) {
        int count = units < SLAB2_UNITS ? units - SLAB1_UNITS
                                        : SLAB2_UNITS - SLAB1_UNITS;
        paise += (long)count * RATE2_PAISE;
    }
    paise += (long)(units < SLAB1_UNITS ? units : SLAB1_UNITS) * RATE1_PAISE;
#ifdef DEBUG
    fprintf(stderr, "[DEBUG] units=%d bill_paise=%ld\n", units, paise);
#endif
    return paise;
}

int main(void)
{
    int units = 150;
    long bill = compute_bill(units);
    printf("Units: %d, bill: Rs %ld.%02ld\n", units, bill / 100, bill % 100);
    return 0;
}
