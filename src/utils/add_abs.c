#include "../s21_decimal.h"

int add_abs(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
    unsigned int carry = 0;
    for (int i = 0; i < 3; i++) {
        unsigned long long sum = (unsigned int)value_1.bits[i] + (unsigned int)value_2.bits[i] + carry;
        result->bits[i] = sum & 0xFFFFFFFF;
        carry = sum >> 32;
    }
    return carry != 0;
}
