#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result){
    int error = 0;
    error = copy_decimal(value, result);
    result->bits[3] ^= (1 << 31);
    return error;
}
