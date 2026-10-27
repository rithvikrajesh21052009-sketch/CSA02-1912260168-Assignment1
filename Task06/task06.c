#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
    int units;
    printf("Enter units consumed: ");
    if (scanf("%d", &units) != 1 || units < 0) {
        fprintf(stderr, "Invalid input: enter a non-negative whole number.\n");
        return 1;
    }

    /* Example slab charge: first 100 free, next 100 at 225 paise, rest at 450 paise. */
    long long energy = 0;
    if (units > 100) {
        int slab2 = units < 200 ? units - 100 : 100;
        energy += (long long)slab2 * 225;
    }
    if (units > 200) energy += (long long)(units - 200) * 450;
    long long total = 5000 + energy;

    printf("Energy charge: Rs %lld.%02lld\n", energy / 100, energy % 100);
    printf("Fixed charge: Rs 50.00\n");
    printf("Total bill: Rs %lld.%02lld\n", total / 100, total % 100);
    return 0;
}
