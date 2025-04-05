#include <stdio.h>

int octalToDecimal(unsigned int num) {
    if (num == 0)
        return 0;

    return (num % 10) + 8 * octalToDecimal(num / 10);
}

int main() {
    unsigned int octal = 123;

    printf("Decimal number is %d\n", octalToDecimal(octal));

    return 0;
}
