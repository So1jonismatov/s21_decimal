#ifndef _S21_UTILS_
#define _S21_UTILS_
#include "../s21_decimal.h"

int set_bit(s21_decimal * number, int i, int j);
int set_sign(s21_decimal * number);
int unset_sign(s21_decimal * number);
int set_exponent(s21_decimal *number, int exponent);
void remove_char(const char *src, char *dest, char to_remove);
int divide_by_10(s21_decimal *d);
int multiply_by_10(s21_decimal *d);
int get_exponent(s21_decimal number);
int get_sign(s21_decimal number);
int is_zero(s21_decimal number);
int make_same_exponent(s21_decimal *a, s21_decimal *b);


#endif
