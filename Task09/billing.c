#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define METER_MAX 65535U
#define SLAB1_UNITS 100U
#define SLAB2_UNITS 200U
#define RATE1_PAISE 0LL
#define RATE2_PAISE 225LL
#define RATE3_PAISE 450LL
#define FIXED_CHARGE_PAISE 5000LL

static unsigned int calculate_units(unsigned int previous, unsigned int current)
{
    if (current >= previous) return current - previous;
    /* Treat a decrease as rollover only when previous is near the top of the register. */
    if (previous > METER_MAX - 1000U)
        return (METER_MAX + 1U - previous) + current;
    return UINT_MAX; /* invalid-reading marker */
}

static long long calculate_bill(unsigned int units)
{
    long long energy = 0;
    if (units > SLAB1_UNITS) {
        unsigned int n = units < SLAB2_UNITS ? units - SLAB1_UNITS
                                              : SLAB2_UNITS - SLAB1_UNITS;
        energy += (long long)n * RATE2_PAISE;
    }
    if (units > SLAB2_UNITS)
        energy += (long long)(units - SLAB2_UNITS) * RATE3_PAISE;
    energy += (long long)(units < SLAB1_UNITS ? units : SLAB1_UNITS) * RATE1_PAISE;
    return FIXED_CHARGE_PAISE + energy;
}

int main(void)
{
    unsigned int previous, current;
    printf("Enter previous and current meter readings (0..65535): ");
    if (scanf("%u %u", &previous, &current) != 2 ||
        previous > METER_MAX || current > METER_MAX) {
        fprintf(stderr, "Invalid input. Readings must be integers from 0 to 65535.\n");
        return 1;
    }

    unsigned int units = calculate_units(previous, current);
    if (units == UINT_MAX) {
        fprintf(stderr, "Invalid decreasing reading; rollover rule not satisfied.\n");
        return 1;
    }
    long long bill = calculate_bill(units);
    printf("Units consumed: %u\n", units);
    printf("Energy charge: Rs %lld.%02lld\n",
           (bill - FIXED_CHARGE_PAISE) / 100, (bill - FIXED_CHARGE_PAISE) % 100);
    printf("Fixed charge: Rs 50.00\n");
    printf("Total bill: Rs %lld.%02lld\n", bill / 100, bill % 100);
    return 0;
}
