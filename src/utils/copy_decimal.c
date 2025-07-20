#include "../s21_decimal.h"

int copy_decimal(s21_decimal src, s21_decimal *dst) {
    if (!dst) return 1;
    for(int i = 0; i < 4; i++) {
        dst->bits[i] = src.bits[i];
    }
    return 0;
}
