#include "../s21_decimal.h"
#include "../others/s21_others.h"
#include "../arithmetic/s21_arithmetic.h"

int get_frac(s21_decimal value, s21_decimal *result){
    int error = 0;
    if(result == NULL)
        return 1;
    s21_decimal value_int = {0};
    error |= s21_truncate(value, &value_int);
    error |= s21_sub(value, value_int, result);

    return error;
}
