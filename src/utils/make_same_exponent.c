#include "../s21_decimal.h"


int make_same_exponent(s21_decimal *a, s21_decimal *b) {
    int exp_a = get_exponent(*a);
    int exp_b = get_exponent(*b);
    int error_code = 0;

    if (exp_a == exp_b) {
        return 0;
    }

    s21_decimal *smaller_exp_decimal = (exp_a < exp_b) ? a : b;
    int target_exp = (exp_a < exp_b) ? exp_b : exp_a;

    while (get_exponent(*smaller_exp_decimal) < target_exp && error_code == 0) {
        error_code = multiply_by_10(smaller_exp_decimal);

        if (error_code == 0) {
            int current_exp = get_exponent(*smaller_exp_decimal);
            set_exponent(smaller_exp_decimal, current_exp + 1);
        }
    }

    return error_code; // 0 if success, 1 if overflow occurred.
}
