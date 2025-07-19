#include "../s21_decimal.h"

int get_exponent(s21_decimal value) {
    // mask for bits 16-23.
    const int exponent_mask = 0x00FF0000;
    int isolated_exponent = value.bits[3] & exponent_mask;
    return isolated_exponent >> 16;
}
