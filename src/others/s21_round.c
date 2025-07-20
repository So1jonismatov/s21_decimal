#include "../s21_decimal.h"
#include "../utils/s21_utils.h"
#include "../convertors/s21_convertors.h"
#include "../comparison/s21_comparison.h"
#include "s21_others.h"

int s21_round(s21_decimal value, s21_decimal *result) {
    if (result == NULL) {
        return 1;
    }

    int error = 0;
    s21_decimal fractional_part = {0};
    s21_decimal half = {0};

    s21_from_int_to_decimal(5, &half);
    set_exponent(&half, 1);

    error |= get_frac(value, &fractional_part);

    if (get_sign(fractional_part)) {
        s21_negate(fractional_part, &fractional_part);
    }

    if (s21_is_greater_or_equal(fractional_part, half)) {
        if (get_sign(value)) {
            error |= s21_floor(value, result);
        } else {
            error |= s21_ceil(value, result);
        }
    } else {
        error |= s21_truncate(value, result);
    }

    return error;
}
