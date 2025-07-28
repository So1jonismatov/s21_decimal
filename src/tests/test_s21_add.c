#include "../s21_decimal.h"
#include <check.h>
#include <stdlib.h>

START_TEST(add_normal) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(123, &val1);
    s21_from_int_to_decimal(456, &val2);
    s21_from_int_to_decimal(579, &expected);
    int code = s21_add(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_negative) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(-123, &val1);
    s21_from_int_to_decimal(-456, &val2);
    s21_from_int_to_decimal(-579, &expected);
    int code = s21_add(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_pos_neg) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(123, &val1);
    s21_from_int_to_decimal(-456, &val2);
    s21_from_int_to_decimal(-333, &expected);
    int code = s21_add(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_neg_pos) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(-123, &val1);
    s21_from_int_to_decimal(456, &val2);
    s21_from_int_to_decimal(333, &expected);
    int code = s21_add(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_zero) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(123, &val1);
    s21_from_int_to_decimal(0, &val2);
    s21_from_int_to_decimal(123, &expected);
    int code = s21_add(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_different_scale) {
    s21_decimal val1, val2, res, expected;
    s21_from_float_to_decimal(123.456, &val1);
    s21_from_float_to_decimal(78.9, &val2);
    s21_from_float_to_decimal(202.356, &expected);
    int code = s21_add(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_overflow) {
    s21_decimal val1, val2, res;
    val1.bits[0] = 0xFFFFFFFF;
    val1.bits[1] = 0xFFFFFFFF;
    val1.bits[2] = 0xFFFFFFFF;
    val1.bits[3] = 0;
    s21_from_int_to_decimal(1, &val2);
    int code = s21_add(val1, val2, &res);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(add_neg_overflow) {
    s21_decimal val1, val2, res;
    val1.bits[0] = 0xFFFFFFFF;
    val1.bits[1] = 0xFFFFFFFF;
    val1.bits[2] = 0xFFFFFFFF;
    val1.bits[3] = 0;
    set_sign(&val1);
    s21_from_int_to_decimal(-1, &val2);
    int code = s21_add(val1, val2, &res);
    ck_assert_int_eq(code, 2);
}
END_TEST

START_TEST(add_to_zero) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(123, &val1);
    s21_from_int_to_decimal(-123, &val2);
    s21_from_int_to_decimal(0, &expected);
    int code = s21_add(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(add_null_result) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(123, &val1);
    s21_from_int_to_decimal(456, &val2);
    int code = s21_add(val1, val2, NULL);
    ck_assert_int_eq(code, 1);
}
END_TEST

Suite * s21_test_add(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("s21_add");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, add_normal);
    tcase_add_test(tc_core, add_negative);
    tcase_add_test(tc_core, add_pos_neg);
    tcase_add_test(tc_core, add_neg_pos);
    tcase_add_test(tc_core, add_zero);
    tcase_add_test(tc_core, add_different_scale);
    tcase_add_test(tc_core, add_overflow);
    tcase_add_test(tc_core, add_neg_overflow);
    tcase_add_test(tc_core, add_to_zero);
    tcase_add_test(tc_core, add_null_result);
    suite_add_tcase(s, tc_core);

    return s;
}
