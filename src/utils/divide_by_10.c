#include "../s21_decimal.h"

int divide_by_10(s21_decimal *d) {
    unsigned long long remainder = 0;
    for (int i = 2; i >= 0; i--) {
        unsigned long long temp = (remainder << 32) | (unsigned int)d->bits[i];
        d->bits[i] = temp / 10;
        remainder = temp % 10;
    }
    return (int)remainder;
}
