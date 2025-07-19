#include "../s21_decimal.h"
#include "../utils/s21_utils.h"


int s21_is_equal(s21_decimal a, s21_decimal b) {
    if (is_zero(a) && is_zero(b)) {
        return 1;
    }
    if (get_sign(a) != get_sign(b)) {
        return 0;
    }



    make_same_exponent(&a, &b);
    for (int i = 0; i < 3; i++) {
        if (a.bits[i] != b.bits[i]) {
            return 0;
        }
    }

    return 1;
}
