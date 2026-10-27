#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/*
 * Demonstration model:
 * - Input energy is in Wh for one 15-minute interval.
 * - Peak is 18:00 inclusive to 22:00 exclusive.
 * - Base tariff is read at runtime in paise/kWh.
 * - Peak tariff is 20% higher.
 * - This simple model rounds each interval charge to the nearest paise.
 *
 * Production systems should define how interval energy is split if an interval
 * crosses a tariff boundary, and should validate configuration files robustly.
 */

static uint64_t charge_paise(uint64_t wh, uint64_t base_rate_paise_per_kwh,
                             int peak)
{
    /* numerator represents paise * 1000; peak factor is 120/100. */
    uint64_t numerator = wh * base_rate_paise_per_kwh;
    if (peak) numerator = (numerator * 120U + 50U) / 100U;
    /* Round Wh * paise/kWh to paise: divide by 1000, nearest integer. */
    return (numerator + 500U) / 1000U;
}

int main(void)
{
    uint64_t wh, base_rate;
    int peak;
    printf("Enter interval energy in Wh: ");
    if (scanf("%" SCNu64, &wh) != 1) {
        fprintf(stderr, "Invalid Wh value.\n");
        return 1;
    }
    printf("Enter base tariff in paise/kWh (e.g. 800): ");
    if (scanf("%" SCNu64, &base_rate) != 1 || base_rate == 0) {
        fprintf(stderr, "Invalid tariff.\n");
        return 1;
    }
    printf("Peak interval? Enter 1 for 18:00-22:00, otherwise 0: ");
    if (scanf("%d", &peak) != 1 || (peak != 0 && peak != 1)) {
        fprintf(stderr, "Peak flag must be 0 or 1.\n");
        return 1;
    }

    uint64_t cost = charge_paise(wh, base_rate, peak);
    printf("Interval energy: %" PRIu64 " Wh\n", wh);
    printf("Tariff period: %s\n", peak ? "peak (+20%)" : "normal");
    printf("Charge: Rs %" PRIu64 ".%02" PRIu64 "\n", cost / 100U, cost % 100U);
    return 0;
}
