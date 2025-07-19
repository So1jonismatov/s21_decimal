#include "../s21_decimal.h"
#include "s21_comparison.h"
int s21_is_less_or_equal(s21_decimal a, s21_decimal b){
    if (s21_is_greater(a, b) || s21_is_equal(a, b)) {
        return 1;
    }
    return 0;
}
