#include "../s21_decimal.h"

int shift_left(s21_decimal *d) {
    int overflow = (d->bits[2] >> 31) & 1;
    d->bits[2] = (d->bits[2] << 1) | ((d->bits[1] >> 31) & 1);
    d->bits[1] = (d->bits[1] << 1) | ((d->bits[0] >> 31) & 1);
    d->bits[0] <<= 1;
    return overflow;
}
