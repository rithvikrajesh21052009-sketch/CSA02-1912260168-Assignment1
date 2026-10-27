#include <stdio.h>

int main(void)
{
    printf("5 / 2 as integer = %d\n", 5 / 2);
    printf("5 / 2 after conversion = %.2f\n", (double)5 / 2);
    printf("0.1 + 0.2 = %.17f\n", 0.1 + 0.2);
    printf("integer paise for Rs 162.50 = %lld\n", 16250LL);
    return 0;
}
