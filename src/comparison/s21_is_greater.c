#include "../s21_decimal.h"
#include "s21_comparison.h"

int s21_is_greater(s21_decimal a, s21_decimal b){
    return s21_is_less(b, a);
}
