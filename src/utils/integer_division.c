#include <string.h>
#include "../s21_decimal.h"


void integer_division(s21_decimal dividend, s21_decimal divisor, s21_decimal *quotient, s21_decimal *remainder) {
    memset(quotient, 0, sizeof(s21_decimal));
    memset(remainder, 0, sizeof(s21_decimal));

    for (int i = 95; i >= 0; i--) {
        shift_left(remainder);
        set_bit(remainder, 0, get_bit(dividend, i));
        if (s21_is_greater_or_equal(*remainder, divisor)) {
            s21_sub(*remainder, divisor, remainder); // Using your s21_sub, assuming it handles absolute values correctly
            set_bit(quotient, i, 1);
        }
    }
}
