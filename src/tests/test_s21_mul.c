#include "../s21_decimal.h"
#include <check.h>
#include <stdlib.h>

START_TEST(mul_normal) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(123, &val1);
    s21_from_int_to_decimal(456, &val2);
    s21_from_int_to_decimal(56088, &expected);
    int code = s21_mul(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_pos_neg) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(123, &val1);
    s21_from_int_to_decimal(-456, &val2);
    s21_from_int_to_decimal(-56088, &expected);
    int code = s21_mul(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_neg_pos) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(-123, &val1);
    s21_from_int_to_decimal(456, &val2);
    s21_from_int_to_decimal(-56088, &expected);
    int code = s21_mul(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_neg_neg) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(-123, &val1);
    s21_from_int_to_decimal(-456, &val2);
    s21_from_int_to_decimal(56088, &expected);
    int code = s21_mul(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_by_zero) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(123, &val1);
    s21_from_int_to_decimal(0, &val2);
    s21_from_int_to_decimal(0, &expected);
    int code = s21_mul(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_by_one) {
    s21_decimal val1, val2, res, expected;
    s21_from_int_to_decimal(123, &val1);
    s21_from_int_to_decimal(1, &val2);
    s21_from_int_to_decimal(123, &expected);
    int code = s21_mul(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_floats) {
    s21_decimal val1, val2, res, expected;
    s21_from_float_to_decimal(12.3, &val1);
    s21_from_float_to_decimal(4.56, &val2);
    s21_from_float_to_decimal(56.088, &expected);
    int code = s21_mul(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_large_numbers) {
    s21_decimal val1, val2, res, expected;
    val1.bits[0] = 0xFFFFFFFF;
    val1.bits[1] = 0xFFFFFFFF;
    val1.bits[2] = 0;
    val1.bits[3] = 0;
    s21_from_int_to_decimal(1, &val2);
    expected.bits[0] = 0xFFFFFFFF;
    expected.bits[1] = 0xFFFFFFFF;
    expected.bits[2] = 0;
    expected.bits[3] = 0;
    int code = s21_mul(val1, val2, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_overflow) {
    s21_decimal val1, val2, res;
    val1.bits[0] = 0xFFFFFFFF;
    val1.bits[1] = 0xFFFFFFFF;
    val1.bits[2] = 0xFFFFFFFF;
    val1.bits[3] = 0;
    s21_from_int_to_decimal(2, &val2);
    int code = s21_mul(val1, val2, &res);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(mul_neg_overflow) {
    s21_decimal val1, val2, res;
    val1.bits[0] = 0xFFFFFFFF;
    val1.bits[1] = 0xFFFFFFFF;
    val1.bits[2] = 0xFFFFFFFF;
    val1.bits[3] = 0;
    set_sign(&val1);
    s21_from_int_to_decimal(2, &val2);
    int code = s21_mul(val1, val2, &res);
    ck_assert_int_eq(code, 2);
}
END_TEST

START_TEST(mul_null_result) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(123, &val1);
    s21_from_int_to_decimal(456, &val2);
    int code = s21_mul(val1, val2, NULL);
    ck_assert_int_eq(code, 1);
}
END_TEST

Suite * s21_test_mul(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("s21_mul");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, mul_normal);
    tcase_add_test(tc_core, mul_pos_neg);
    tcase_add_test(tc_core, mul_neg_pos);
    tcase_add_test(tc_core, mul_neg_neg);
    tcase_add_test(tc_core, mul_by_zero);
    tcase_add_test(tc_core, mul_by_one);
    tcase_add_test(tc_core, mul_floats);
    tcase_add_test(tc_core, mul_large_numbers);
    tcase_add_test(tc_core, mul_overflow);
    tcase_add_test(tc_core, mul_neg_overflow);
    tcase_add_test(tc_core, mul_null_result);
    suite_add_tcase(s, tc_core);

    return s;
}
