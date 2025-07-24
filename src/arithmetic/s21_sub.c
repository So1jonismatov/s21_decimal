#include "../s21_decimal.h"
#include <string.h>



int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    if (result == NULL) {
        return 1; // Error: null pointer
    }
    memset(result, 0, sizeof(s21_decimal));

    int sign1 = get_sign(value_1);
    int sign2 = get_sign(value_2);

    int error = make_same_exponent(&value_1, &value_2);
    if (error) {
        return error; // Propagate overflow from normalization
    }
    set_exponent(result, get_exponent(value_1));

    if (sign1 != sign2) {
        // (+A) - (-B) becomes +(A + B)
        // (-A) - (+B) becomes -(A + B)
        error = add_abs(value_1, value_2, result);
        if (sign1) {
            set_sign(result);
        }

        if (error) {
            return sign1 ? 2 : 1; // 2 for negative overflow, 1 for positive
        }
    } else { // Signs are the same
        unset_sign(&value_1);
        unset_sign(&value_2);

        if (s21_is_less(value_1, value_2)) {
            // Case: |value_1| < |value_2|
            // (+A) - (+B) where A < B results in -(B - A)
            // (-A) - (-B) where A < B results in +(B - A)
            sub_abs(value_2, value_1, result);
            if (!sign1) { // If original sign was positive, result is negative
                set_sign(result);
            }
        } else {
            // Case: |value_1| >= |value_2|
            // (+A) - (+B) where A >= B results in +(A - B)
            // (-A) - (-B) where A >= B results in -(A - B)
            sub_abs(value_1, value_2, result);
            if (sign1) { // If original sign was negative, result is negative
                set_sign(result);
            }
        }
    }

    return 0; // OK
}
