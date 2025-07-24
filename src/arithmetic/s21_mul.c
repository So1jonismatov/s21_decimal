#include "../s21_decimal.h"
#include <string.h>


int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    if (!result) return 1;
    memset(result, 0, sizeof(s21_decimal));

    int sign1 = get_sign(value_1);
    int sign2 = get_sign(value_2);
    int result_sign = sign1 ^ sign2;

    if (is_zero(value_1) || is_zero(value_2)) {
        return 0; // Result is 0, which is the initial state
    }

    int result_exp = get_exponent(value_1) + get_exponent(value_2);

    s21_decimal temp_res = {0};
    unset_sign(&value_1);

    for (int i = 0; i < 96; i++) {
        if (get_bit(value_2, i)) {
            if (add_abs(temp_res, value_1, &temp_res)) {
                 if (result_exp > 28) break; // Will be handled later
                 return result_sign ? 2 : 1;
            }
        }
        if (shift_left(&value_1)) {
            // Check if there are any remaining bits in value_2 to be processed
            for(int j = i + 1; j < 96; j++) {
                if(get_bit(value_2, j)) {
                    if (result_exp > 28) break;
                    return result_sign ? 2 : 1; // Overflow
                }
            }
        }
    }

    *result = temp_res;

    // Normalize exponent
    while (result_exp > 28) {
        if (is_zero(*result)) { // If result is 0, we can just set exp to 0
            result_exp = 0;
            break;
        }
        // For proper rounding, we'd check the remainder
        int remainder = divide_by_10(result);
        if (remainder >= 5) { // Simple rounding
            s21_decimal one = {{1, 0, 0, 0}};
            add_abs(*result, one, result);
        }
        result_exp--;
    }

    set_exponent(result, result_exp);
    if (result_sign) {
        set_sign(result);
    }

    if (result_exp > 28) {
        memset(result, 0, sizeof(s21_decimal));
        return result_sign ? 2 : 1;
    }

    return 0;
}
