#include "../s21_decimal.h"
#include <check.h>
#include <stdlib.h>

START_TEST(round_null_result) {
    s21_decimal val;
    s21_from_int_to_decimal(1, &val);
    int code = s21_round(val, NULL);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(round_pos_up) {
    s21_decimal val, res, expected;
    s21_from_float_to_decimal(123.7f, &val);
    s21_from_int_to_decimal(124, &expected);
    s21_round(val, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(round_pos_down) {
    s21_decimal val, res, expected;
    s21_from_float_to_decimal(123.4f, &val);
    s21_from_int_to_decimal(123, &expected);
    s21_round(val, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(round_pos_half) {
    s21_decimal val, res, expected;
    s21_from_float_to_decimal(123.5f, &val);
    s21_from_int_to_decimal(124, &expected);
    s21_round(val, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(round_neg_down) {
    s21_decimal val, res, expected;
    s21_from_float_to_decimal(-123.7f, &val);
    s21_from_int_to_decimal(-124, &expected);
    s21_round(val, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(round_neg_up) {
    s21_decimal val, res, expected;
    s21_from_float_to_decimal(-123.4f, &val);
    s21_from_int_to_decimal(-123, &expected);
    s21_round(val, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(round_neg_half) {
    s21_decimal val, res, expected;
    s21_from_float_to_decimal(-123.5f, &val);
    s21_from_int_to_decimal(-124, &expected);
    s21_round(val, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(round_integer) {
    s21_decimal val, res, expected;
    s21_from_int_to_decimal(-300, &val);
    s21_from_int_to_decimal(-300, &expected);
    s21_round(val, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

Suite * s21_test_round(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("s21_round");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, round_null_result);
    tcase_add_test(tc_core, round_pos_up);
    tcase_add_test(tc_core, round_pos_down);
    tcase_add_test(tc_core, round_pos_half);
    tcase_add_test(tc_core, round_neg_down);
    tcase_add_test(tc_core, round_neg_up);
    tcase_add_test(tc_core, round_neg_half);
    tcase_add_test(tc_core, round_integer);
    suite_add_tcase(s, tc_core);

    return s;
}
