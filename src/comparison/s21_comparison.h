#ifndef _S21_COMPARISON_H_
#define _S21_COMPARISON_H_
#include "../s21_decimal.h"

int s21_is_equal(s21_decimal a, s21_decimal b);
int s21_is_less(s21_decimal a, s21_decimal b);
int s21_is_greater(s21_decimal a, s21_decimal b);
int s21_is_greater_or_equal(s21_decimal a, s21_decimal b);
int s21_is_less_or_equal(s21_decimal a, s21_decimal b);
int s21_is_not_equal(s21_decimal, s21_decimal);

#endif
