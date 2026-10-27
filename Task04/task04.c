#include <stdio.h>

#define SQUARE(x) (((x) * (x)))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define RUPEES_TO_PAISE(r) ((long long)(r) * 100LL)

static inline int square_int(int x) { return x * x; }
static inline int max_int(int a, int b) { return a > b ? a : b; }

int main(void)
{
    int a = 3, b = 7;
    printf("SQUARE(a + 1) = %d\n", SQUARE(a + 1));
    printf("MAX(a, b) = %d\n", MAX(a, b));
    printf("RUPEES_TO_PAISE(50) = %lld\n", RUPEES_TO_PAISE(50));
    printf("inline square = %d, inline max = %d\n",
           square_int(a + 1), max_int(a, b));
    return 0;
}
