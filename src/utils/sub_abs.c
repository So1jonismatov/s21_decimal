#include "../s21_decimal.h"

int sub_abs(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int borrow = 0;
    for (int i = 0; i < 3; i++) {
        long long diff = (unsigned int)value_1.bits[i] - (unsigned int)value_2.bits[i] - borrow;
        if (diff < 0) {
            result->bits[i] = (unsigned int)(diff + 0x100000000); // 2^32
            borrow = 1;
        } else {
            result->bits[i] = (unsigned int)diff;
            borrow = 0;
        }
    }
    return 0;
}
