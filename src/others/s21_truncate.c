#include "../s21_decimal.h"
#include "../utils/s21_utils.h"
#include <stdlib.h>

int s21_truncate(s21_decimal value, s21_decimal *result) {
    if (result == NULL) {
        return 1;
    }
    *result = value;

    int scale = get_exponent(value);
    if (scale == 0) {
        return 0;
    }
    for (int i = 0; i < scale; i++) {
        divide_by_10(result);
    }
    set_exponent(result, 0);

    return 0; // OK
}
