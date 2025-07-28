#include "../s21_decimal.h"
#include <string.h>

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    if (!result) return 1;
    memset(result, 0, sizeof(s21_decimal));

    int sign1 = get_sign(value_1);
    int sign2 = get_sign(value_2);
    int result_sign = sign1 ^ sign2;

    if (is_zero(value_1) || is_zero(value_2)) {
        return 0; // Result is 0
    }

    int result_exp = get_exponent(value_1) + get_exponent(value_2);

    s21_decimal temp_res = {0};
    unset_sign(&value_1);
    unset_sign(&value_2);

    for (int i = 0; i < 96; i++) {
        if (get_bit(value_2, i)) {
            // Add value_1 to the temporary result.
            if (add_abs(temp_res, value_1, &temp_res)) {
                // If the addition causes an overflow, the number is too large for this
                // algorithm to handle. We must return an error.
                memset(result, 0, sizeof(s21_decimal));
                return result_sign ? 2 : 1;
            }
        }

        // Check if the most significant bit is 1 BEFORE shifting.
        // If it is, the subsequent shift will cause an overflow.
        if (get_bit(value_1, 95)) {
            // If an overflow is about to happen, we must check if there are any
            // more additions to do. If there are, it's a guaranteed error.
            for (int k = i + 1; k < 96; k++) {
                if (get_bit(value_2, k)) {
                    memset(result, 0, sizeof(s21_decimal));
                    return result_sign ? 2 : 1; // Error: too large/small
                }
            }
        }
        shift_left(&value_1);
    }

    *result = temp_res;

    // Normalize exponent with Bank Rounding
    while (result_exp > 28) {
        if (is_zero(*result)) {
            result_exp = 0;
            break;
        }

        int remainder = divide_by_10(result);
        result_exp--;

        if (bank_round(result, remainder)) {
            // Overflow while rounding up
            memset(result, 0, sizeof(s21_decimal));
            return result_sign ? 2 : 1;
        }
    }

    set_exponent(result, result_exp);
    if (result_sign) {
        set_sign(result);
    }

    return 0;
}
