#include "../s21_decimal.h"
#include <string.h>

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    if (!result) return 1;
    if (is_zero(value_2)) return 3;

    memset(result, 0, sizeof(s21_decimal));
    if (is_zero(value_1)) return 0;

    int sign1 = get_sign(value_1);
    int sign2 = get_sign(value_2);
    int result_sign = sign1 ^ sign2;

    unset_sign(&value_1);
    unset_sign(&value_2);

    int final_scale = get_exponent(value_1) - get_exponent(value_2);
    set_exponent(&value_1, 0);
    set_exponent(&value_2, 0);

    s21_decimal quotient, remainder;
    integer_division(value_1, value_2, &quotient, &remainder);

    // Handle fractional part
    s21_decimal fraction_quotient = {0};
    while (final_scale < 28 && !is_zero(remainder)) {
        multiply_by_10(&remainder);
        integer_division(remainder, value_2, &fraction_quotient, &remainder);
        multiply_by_10(&quotient);
        s21_add(quotient, fraction_quotient, &quotient);
        final_scale++;
    }

    *result = quotient;


    while (final_scale > 28) {
        divide_by_10(result);
        final_scale--;
    }


    while (final_scale < 0) {
        if(multiply_by_10(result)) {
            return result_sign ? 2 : 1;
        }
        final_scale++;
    }

    set_exponent(result, final_scale);
    if (result_sign) {
        set_sign(result);
    }

    return 0;
}
