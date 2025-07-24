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
    int is_less = 0;

    for (int i = 2; i >= 0; i--) {
        if (a.bits[i] < b.bits[i]) {
            is_less = 1;
            break;
        }
        if (a.bits[i] > b.bits[i]) {
            is_less = 0;
            break;
        }

    }

    if (sign_a) {
        if (!is_less) {
             result = 1;
        }
    } else {
        result = is_less;
    }
    if(sign_a == is_less){
        result = 1;
    }else{
        result = 0;
    }

    return result;
}
