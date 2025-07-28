#include "../s21_decimal.h"
#include <check.h>
#include <stdlib.h>

START_TEST(floor_null_result) {
    s21_decimal val;
    s21_from_int_to_decimal(1, &val);
    int code = s21_floor(val, NULL);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(floor_pos_float) {
    s21_decimal val, res, expected;
    s21_from_float_to_decimal(123.789f, &val);
    s21_from_int_to_decimal(123, &expected);
    s21_floor(val, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(floor_neg_float) {
    s21_decimal val, res, expected;
    s21_from_float_to_decimal(-123.789f, &val);
    s21_from_int_to_decimal(-124, &expected);
    s21_floor(val, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(floor_integer) {
    s21_decimal val, res, expected;
    s21_from_int_to_decimal(-250, &val);
    s21_from_int_to_decimal(-250, &expected);
    s21_floor(val, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(floor_zero) {
    s21_decimal val, res, expected;
    s21_from_int_to_decimal(0, &val);
    s21_from_int_to_decimal(0, &expected);
    s21_floor(val, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

Suite * s21_test_floor(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("s21_floor");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, floor_null_result);
    tcase_add_test(tc_core, floor_pos_float);
    tcase_add_test(tc_core, floor_neg_float);
    tcase_add_test(tc_core, floor_integer);
    tcase_add_test(tc_core, floor_zero);
    suite_add_tcase(s, tc_core);

    return s;
}
