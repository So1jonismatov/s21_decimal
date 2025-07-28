#include "../s21_decimal.h"
#include <check.h>
#include <stdlib.h>

START_TEST(truncate_null_result) {
    s21_decimal val;
    s21_from_int_to_decimal(1, &val);
    int code = s21_truncate(val, NULL);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(truncate_pos_float) {
    s21_decimal val, res, expected;
    s21_from_float_to_decimal(123.456f, &val);
    s21_from_int_to_decimal(123, &expected);
    int code = s21_truncate(val, &res);
    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(truncate_neg_float) {
    s21_decimal val, res, expected;
    s21_from_float_to_decimal(-987.654f, &val);
    s21_from_int_to_decimal(-987, &expected);
    int code = s21_truncate(val, &res);
    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(truncate_integer) {
    s21_decimal val, res, expected;
    s21_from_int_to_decimal(12345, &val);
    s21_from_int_to_decimal(12345, &expected);
    int code = s21_truncate(val, &res);
    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(truncate_zero) {
    s21_decimal val, res, expected;
    s21_from_int_to_decimal(0, &val);
    s21_from_int_to_decimal(0, &expected);
    int code = s21_truncate(val, &res);
    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

Suite * s21_test_truncate(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("s21_truncate");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, truncate_null_result);
    tcase_add_test(tc_core, truncate_pos_float);
    tcase_add_test(tc_core, truncate_neg_float);
    tcase_add_test(tc_core, truncate_integer);
    tcase_add_test(tc_core, truncate_zero);
    suite_add_tcase(s, tc_core);

    return s;
}
