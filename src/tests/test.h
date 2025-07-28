#ifndef S21_TEST_H
#define S21_TEST_H

#include <check.h>

// Arithmetic Suites
Suite *s21_test_add(void);
Suite *s21_test_sub(void);
Suite *s21_test_mul(void);
Suite *s21_test_div(void);

// Comparison Suites
Suite *s21_test_is_equal(void);
Suite *s21_test_is_not_equal(void);
Suite *s21_test_is_less(void);
Suite *s21_test_is_less_or_equal(void);
Suite *s21_test_is_greater(void);
Suite *s21_test_is_greater_or_equal(void);

// Converter Suites
Suite *s21_test_from_int_to_decimal(void);
Suite *s21_test_from_float_to_decimal(void);
Suite *s21_test_from_decimal_to_int(void);
Suite *s21_test_from_decimal_to_float(void);

// Other Function Suites
Suite *s21_test_truncate(void);
Suite *s21_test_floor(void);
Suite *s21_test_round(void);
Suite *s21_test_negate(void);

#endif // S21_TEST_H
