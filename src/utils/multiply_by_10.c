#include "../s21_decimal.h"

int multiply_by_10(s21_decimal *d) {
    unsigned long long carry = 0;
    for (int i = 0; i < 3; i++) {
        unsigned long long product = (unsigned int)d->bits[i] * 10 + carry;
        d->bits[i] = product & 0xFFFFFFFF;
        carry = product >> 32;
    }
    return carry != 0;
}
