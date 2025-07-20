#include "../s21_decimal.h"
#include "../comparison/s21_comparison.h"
#include "../others/s21_others.h"
#include "../convertors/s21_convertors.h"
#include "s21_utils.h"
#include "../arithmetic/s21_arithmetic.h"


int s21_ceil(s21_decimal value, s21_decimal *result) {
    if (result == NULL) {
        return 1;
    }

    int error = 0;
    s21_decimal truncated_value = {0};
    s21_truncate(value, &truncated_value);

    if (s21_is_equal(value, truncated_value)) {
        error = copy_decimal(value, result);
    } else {

        if (!get_sign(value)) {
            s21_decimal one = {0};
            error |= s21_from_int_to_decimal(1, &one);
            error |= s21_add(truncated_value, one, result);
        } else
            error = copy_decimal(truncated_value, result);
        }
    }
    return error;
}
