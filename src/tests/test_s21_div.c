#include "../s21_decimal.h"
#include <check.h>
#include <stdlib.h>

START_TEST(div_normal) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(100, &val1);
    s21_from_int_to_decimal(5, &val2);
    s21_from_int_to_decimal(20, &expected);
    int code = s21_div(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_with_remainder) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(10, &val1);
    s21_from_int_to_decimal(3, &val2);
    s21_from_float_to_decimal(3.333333333333333333333333333, &expected);
    int code = s21_div(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_pos_neg) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(100, &val1);
    s21_from_int_to_decimal(-5, &val2);
    s21_from_int_to_decimal(-20, &expected);
    int code = s21_div(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_neg_pos) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(-100, &val1);
    s21_from_int_to_decimal(5, &val2);
    s21_from_int_to_decimal(-20, &expected);
    int code = s21_div(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_neg_neg) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(-100, &val1);
    s21_from_int_to_decimal(-5, &val2);
    s21_from_int_to_decimal(20, &expected);
    int code = s21_div(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_by_zero) {
    s21_decimal val1, val2, res;
    s21_from_int_to_decimal(100, &val1);
    s21_from_int_to_decimal(0, &val2);
    int code = s21_div(val1, val2, &res);
    ck_assert_int_eq(code, 3);
}
END_TEST

START_TEST(div_zero) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(0, &val1);
    s21_from_int_to_decimal(5, &val2);
    s21_from_int_to_decimal(0, &expected);
    int code = s21_div(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_by_one) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(123, &val1);
    s21_from_int_to_decimal(1, &val2);
    s21_from_int_to_decimal(123, &expected);
    int code = s21_div(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_floats) {
    s21_decimal val1, val2, res, expected;
    s21_from_float_to_decimal(56.088, &val1);
    s21_from_float_to_decimal(4.56, &val2);
    s21_from_float_to_decimal(12.3, &expected);
    int code = s21_div(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_scale_up) {
    s21_decimal val1, val2, res, expected;
    s21_from_float_to_decimal(1, &val1);
    s21_from_float_to_decimal(3, &val2);
    s21_from_float_to_decimal(0.3333333333333333333333333333, &expected);
    int code = s21_div(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_scale_down) {
    s21_decimal val1, val2, res, expected;
    val1.bits[0] = 1000000;
    val1.bits[1] = 0;
    val1.bits[2] = 0;
    val1.bits[3] = 0;
    set_exponent(&val1, -2);
    s21_from_int_to_decimal(2, &val2);
    s21_from_int_to_decimal(50000000, &expected);
    int code = s21_div(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(div_overflow) {
    s21_decimal val1, val2, res;
    val1.bits[0] = 0xFFFFFFFF;
    val1.bits[1] = 0xFFFFFFFF;
    val1.bits[2] = 0xFFFFFFFF;
    val1.bits[3] = 0;
    set_exponent(&val1, -1);
    s21_from_float_to_decimal(0.5, &val2);
    int code = s21_div(val1, val2, &res);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(div_neg_overflow) {
    s21_decimal val1, val2, res;
    val1.bits[0] = 0xFFFFFFFF;
    val1.bits[1] = 0xFFFFFFFF;
    val1.bits[2] = 0xFFFFFFFF;
    val1.bits[3] = 0;
    set_exponent(&val1, -1);
    set_sign(&val1);
    s21_from_float_to_decimal(0.5, &val2);
    int code = s21_div(val1, val2, &res);
    ck_assert_int_eq(code, 2);
}
END_TEST

START_TEST(div_null_result) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(100, &val1);
    s21_from_int_to_decimal(5, &val2);
    int code = s21_div(val1, val2, NULL);
    ck_assert_int_eq(code, 1);
}
END_TEST

Suite * s21_test_div(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("s21_div");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, div_normal);
    tcase_add_test(tc_core, div_with_remainder);
    tcase_add_test(tc_core, div_pos_neg);
    tcase_add_test(tc_core, div_neg_pos);
    tcase_add_test(tc_core, div_neg_neg);
    tcase_add_test(tc_core, div_by_zero);
    tcase_add_test(tc_core, div_zero);
    tcase_add_test(tc_core, div_by_one);
    tcase_add_test(tc_core, div_floats);
    tcase_add_test(tc_core, div_scale_up);
    tcase_add_test(tc_core, div_scale_down);
    tcase_add_test(tc_core, div_overflow);
    tcase_add_test(tc_core, div_neg_overflow);
    tcase_add_test(tc_core, div_null_result);

    suite_add_tcase(s, tc_core);

    return s;
}
