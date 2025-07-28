#include "../s21_decimal.h"
#include <check.h>
#include <stdlib.h>
#include <limits.h>

START_TEST(i2d_null_dst) {
    int code = s21_from_int_to_decimal(123, NULL);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(i2d_zero) {
    s21_decimal res;
    s21_decimal expected = {{0, 0, 0, 0}};
    int code = s21_from_int_to_decimal(0, &res);
    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(i2d_positive) {
    s21_decimal res;
    s21_decimal expected = {{12345, 0, 0, 0}};
    int code = s21_from_int_to_decimal(12345, &res);
    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(i2d_negative) {
    s21_decimal res;
    s21_decimal expected = {{54321, 0, 0, 0}};
    set_sign(&expected);
    int code = s21_from_int_to_decimal(-54321, &res);
    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(i2d_int_max) {
    s21_decimal res;
    s21_decimal expected = {{INT_MAX, 0, 0, 0}};
    int code = s21_from_int_to_decimal(INT_MAX, &res);
    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(i2d_int_min) {
    s21_decimal res;
    s21_decimal expected = {{(unsigned)INT_MAX + 1, 0, 0, 0}};
    set_sign(&expected);
    int code = s21_from_int_to_decimal(INT_MIN, &res);
    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

Suite * s21_test_from_int_to_decimal(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("s21_from_int_to_decimal");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, i2d_null_dst);
    tcase_add_test(tc_core, i2d_zero);
    tcase_add_test(tc_core, i2d_positive);
    tcase_add_test(tc_core, i2d_negative);
    tcase_add_test(tc_core, i2d_int_max);
    tcase_add_test(tc_core, i2d_int_min);
    suite_add_tcase(s, tc_core);

    return s;
}
