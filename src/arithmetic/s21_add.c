#include "../s21_decimal.h"
#include <string.h>

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    if (result == NULL) {
        return 1;
    }
    memset(result, 0, sizeof(s21_decimal));

    int sign1 = get_sign(value_1);
    int sign2 = get_sign(value_2);

    // Normalize exponents first.
    int error_code = make_same_exponent(&value_1, &value_2);
    set_exponent(result, get_exponent(value_1));

    if (sign1 == sign2) {
        // Case 1: Same signs (e.g., 5 + 10 or -5 + -10)

        // If normalization already caused an overflow, it's a final error.
        if (error_code) {
            return sign1 ? 2 : 1; // Return neg/pos infinity.
        }

        // Now, perform the addition and check for a new overflow.
        error_code = add_abs(value_1, value_2, result);
        if (error_code) {
            return sign1 ? 2 : 1; // Return neg/pos infinity.
        }

        // If successful, set the result's sign.
        if (sign1) {
            set_sign(result);
        }

    } else {
        // Case 2: Different signs (e.g., 5 + -10 or -5 + 10)
        // This is a subtraction, which cannot overflow the 96-bit mantissa.
        unset_sign(&value_1);
        unset_sign(&value_2);

        if (s21_is_less(value_1, value_2)) {
            sub_abs(value_2, value_1, result);
            if (sign2) { // The sign of the result is the sign of the larger number.
                set_sign(result);
            }
        } else {
            sub_abs(value_1, value_2, result);
            if (sign1) { // The sign of the result is the sign of the larger number.
                set_sign(result);
            }
        }
    }

    // If we've reached this point without returning, it means success.
    return 0; // OK
}
