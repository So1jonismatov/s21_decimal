#include <limits.h>
#include <stdlib.h>
#include "../s21_decimal.h"
#include "../utils/s21_utils.h"
#include "../others/s21_others.h"


int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    if (dst == NULL) {
        return 1;
    }

    s21_decimal truncated_val;
    s21_truncate(src, &truncated_val);

    if (truncated_val.bits[1] != 0 || truncated_val.bits[2] != 0) {
        return 1;
    }
    int sign = get_sign(src);
    if (!sign && truncated_val.bits[0] > INT_MAX) {
        return 1;
    }
    if (sign && truncated_val.bits[0] > (unsigned)INT_MAX + 1) {
        return 1;
    }

    *dst = truncated_val.bits[0];
    if (sign) {
        *dst = -(*dst);
    }

    return 0; // OK
}
