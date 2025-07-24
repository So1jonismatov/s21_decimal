#include <stdlib.h>
#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
    if (result == NULL) return 1;
    s21_decimal value_tr;
    s21_truncate(value, &value_tr);
    if (get_sign(value) && !s21_is_equal(value, value_tr)) {
        s21_decimal one;
        s21_from_int_to_decimal(1, &one);
        s21_sub(value_tr, one, result);
    } else {
        s21_truncate(value, result);
    }
    return 0; // OK
}
