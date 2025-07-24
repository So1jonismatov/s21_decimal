#include "../s21_decimal.h"
#include <string.h>

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    if (result == NULL) {
        return 1;
    }
    memset(result, 0, sizeof(s21_decimal));

    int sign1 = get_sign(value_1);
    int sign2 = get_sign(value_2);

    int error = make_same_exponent(&value_1, &value_2);
    if (error) {
        return error;
    }
    set_exponent(result, get_exponent(value_1));

    if (sign1 == sign2) {
        // (+A) + (+B) = +(A+B)
        // (-A) + (-B) = -(A+B)
        error = add_abs(value_1, value_2, result);
        if (sign1) {
            set_sign(result);
        }
        if (error) {
            return sign1 ? 2 : 1;
        }
    } else {
        unset_sign(&value_1);
        unset_sign(&value_2);

        if (s21_is_less(value_1, value_2)) {
            //  |value_1| < |value_2|
            // (+A) + (-B) if A < B  -> -(B - A),
            // (-A) + (+B) if A < B  -> +(B - A),
            sub_abs(value_2, value_1, result);
            if (sign2) {
                set_sign(result);
            }
        } else {
            // |value_1| >= |value_2|
            // (+A) + (-B) if A >= B -> +(A - B),
            // (-A) + (+B) if A >= B -> -(A - B),
            sub_abs(value_1, value_2, result);
            if (sign1) {
                set_sign(result);
            }
        }
    }
    return 0; // OK
}
