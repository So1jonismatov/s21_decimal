#ifndef S21_CONVERTORS_H
#define S21_CONVERTORS_H
#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);

#endif
