#include "../s21_decimal.h"
#include <check.h>
#include <stdlib.h>

START_TEST(sub_normal) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(456, &val1);
    s21_from_int_to_decimal(123, &val2);
    s21_from_int_to_decimal(333, &expected);
    int code = s21_sub(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(sub_result_negative) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(123, &val1);
    s21_from_int_to_decimal(456, &val2);
    s21_from_int_to_decimal(-333, &expected);
    int code = s21_sub(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(sub_from_negative) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(-123, &val1);
    s21_from_int_to_decimal(456, &val2);
    s21_from_int_to_decimal(-579, &expected);
    int code = s21_sub(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(sub_two_negatives) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(-123, &val1);
    s21_from_int_to_decimal(-456, &val2);
    s21_from_int_to_decimal(333, &expected);
    int code = s21_sub(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(sub_to_zero) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(123, &val1);
    s21_from_int_to_decimal(123, &val2);
    s21_from_int_to_decimal(0, &expected);
    int code = s21_sub(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(sub_from_zero) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(0, &val1);
    s21_from_int_to_decimal(123, &val2);
    s21_from_int_to_decimal(-123, &expected);
    int code = s21_sub(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(sub_different_scale) {
    s21_decimal val1, val2, res, expected;
    s21_from_float_to_decimal(123.456, &val1);
    s21_from_float_to_decimal(78.9, &val2);
    s21_from_float_to_decimal(44.556, &expected);
    int code = s21_sub(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(sub_overflow) {
    s21_decimal val1, val2, res;
    s21_from_int_to_decimal(-2147483647, &val1);
    s21_from_int_to_decimal(1, &val2);
    set_sign(&val1);
    int code = s21_sub(val1, val2, &res);
    ck_assert_int_eq(code, 2);
}
END_TEST

START_TEST(sub_neg_overflow) {
    s21_decimal val1, val2, res;
    s21_from_int_to_decimal(2147483647, &val1);
    s21_from_int_to_decimal(-1, &val2);
    int code = s21_sub(val1, val2, &res);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(sub_null_result) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(123, &val1);
    s21_from_int_to_decimal(456, &val2);
    int code = s21_sub(val1, val2, NULL);
    ck_assert_int_eq(code, 1);
}
END_TEST

Suite * s21_test_sub(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("s21_sub");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, sub_normal);
    tcase_add_test(tc_core, sub_result_negative);
    tcase_add_test(tc_core, sub_from_negative);
    tcase_add_test(tc_core, sub_two_negatives);
    tcase_add_test(tc_core, sub_to_zero);
    tcase_add_test(tc_core, sub_from_zero);
    tcase_add_test(tc_core, sub_different_scale);
    tcase_add_test(tc_core, sub_overflow);
    tcase_add_test(tc_core, sub_neg_overflow);
    tcase_add_test(tc_core, sub_null_result);

    suite_add_tcase(s, tc_core);

    return s;
}
