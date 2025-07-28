#include "../s21_decimal.h"

int s21_is_less(s21_decimal a, s21_decimal b) {
    int sign_a = get_sign(a);
    int sign_b = get_sign(b);

    if (sign_a && !sign_b) {
        return 1;
    }
    if (!sign_a && sign_b) {
        return 0;
    }
    if (is_zero(a) && is_zero(b)) {
        return 0;
    }

    make_same_exponent(&a, &b);

    int result = 0;
    for (int i = 2; i >= 0; i--) {
        if (a.bits[i] != b.bits[i]) {
            result = (a.bits[i] < b.bits[i]) != sign_a;
            return result;
        }
    }

    return 0;
}
