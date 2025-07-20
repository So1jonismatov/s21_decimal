#include "../s21_decimal.h"
#include "../utils/s21_utils.h"
#include <stdlib.h>

int s21_truncate(s21_decimal value, s21_decimal *result) {
    int error = 0;
    if (result == NULL) {
        return 1;
    }
    error = copy_decimal(value, result);

    int scale = get_exponent(value);
    if (scale == 0) {
        return 0;
    }
    for (int i = 0; i < scale; i++) {
        divide_by_10(result);
    }
    error |= set_exponent(result, 0);

    return error; // OK
}
