#include "../s21_decimal.h"
#include <check.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

START_TEST(f2d_null_dst) {
    int code = s21_from_float_to_decimal(123.45f, NULL);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(f2d_nan) {
    s21_decimal res;
    int code = s21_from_float_to_decimal(NAN, &res);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(f2d_inf) {
    s21_decimal res;
    int code = s21_from_float_to_decimal(INFINITY, &res);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(f2d_too_large) {
    s21_decimal res;
    int code = s21_from_float_to_decimal(8e28f, &res);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(f2d_too_small) {
    s21_decimal res;
    int code = s21_from_float_to_decimal(1e-29f, &res);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(f2d_zero) {
    s21_decimal res;
    s21_decimal expected = {{0, 0, 0, 0}};
    int code = s21_from_float_to_decimal(0.0f, &res);
    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(f2d_simple_pos) {
    s21_decimal res;
    s21_decimal expected;
    memset(&expected, 0, sizeof(s21_decimal));
    int code = s21_from_float_to_decimal(123.456f, &res);

    expected.bits[0] = 1234560; // from "1.234560E+02"
    set_exponent(&expected, 4);

    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(f2d_simple_neg) {
    s21_decimal res;
    s21_decimal expected;
    memset(&expected, 0, sizeof(s21_decimal));
    int code = s21_from_float_to_decimal(-987.6543f, &res);

    expected.bits[0] = 9876543; // from "-9.876543E+02"
    set_exponent(&expected, 4);
    set_sign(&expected);

    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(f2d_large_number) {
    s21_decimal res;
    s21_decimal expected;
    memset(&expected, 0, sizeof(s21_decimal));
    int code = s21_from_float_to_decimal(1.234567e15f, &res);

    // from "1.234567E+15" -> mantissa 1234567, exp 15 - 6 = 9
    expected.bits[0] = 1234567;
    for (int i=0; i<9; i++) multiply_by_10(&expected);

    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(f2d_small_number) {
    s21_decimal res;
    s21_decimal expected;
    memset(&expected, 0, sizeof(s21_decimal));
    int code = s21_from_float_to_decimal(1.234567e-15f, &res);

    // from "1.234567E-15" -> mantissa 1234567, exp -15 - 6 = -21
    expected.bits[0] = 1234567;
    set_exponent(&expected, 21);

    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(f2d_precision_loss_rounding) {
    s21_decimal res;
    s21_decimal expected;
    memset(&expected, 0, sizeof(s21_decimal));
    // float rounds 123456789 to 1.2345679E+8
    int code = s21_from_float_to_decimal(123456789.0f, &res);

    expected.bits[0] = 123456790;

    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(f2d_max_scale_boundary) {
    s21_decimal res;
    s21_decimal expected;
    memset(&expected, 0, sizeof(s21_decimal));
    int code = s21_from_float_to_decimal(1.234567e-22f, &res);

    // exp -22 - 6 = -28. Scale becomes 28
    expected.bits[0] = 1234567;
    set_exponent(&expected, 28);

    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(f2d_overflow_on_scale_up) {
    s21_decimal res;
    // This float is valid, but scaling it up will overflow the decimal
    int code = s21_from_float_to_decimal(1e28f, &res);
    ck_assert_int_eq(code, 1);
}
END_TEST

Suite * s21_test_from_float_to_decimal(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("s21_from_float_to_decimal");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, f2d_null_dst);
    tcase_add_test(tc_core, f2d_nan);
    tcase_add_test(tc_core, f2d_inf);
    tcase_add_test(tc_core, f2d_too_large);
    tcase_add_test(tc_core, f2d_too_small);
    tcase_add_test(tc_core, f2d_zero);
    tcase_add_test(tc_core, f2d_simple_pos);
    tcase_add_test(tc_core, f2d_simple_neg);
    tcase_add_test(tc_core, f2d_large_number);
    tcase_add_test(tc_core, f2d_small_number);
    tcase_add_test(tc_core, f2d_precision_loss_rounding);
    tcase_add_test(tc_core, f2d_max_scale_boundary);
    tcase_add_test(tc_core, f2d_overflow_on_scale_up);
    suite_add_tcase(s, tc_core);

    return s;
}
