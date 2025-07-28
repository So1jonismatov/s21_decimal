#include "../s21_decimal.h"
#include <check.h>

START_TEST(negate_positive) {
    s21_decimal val, res, expected;
    s21_from_int_to_decimal(123, &val);
    s21_from_int_to_decimal(-123, &expected);
    s21_negate(val, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(negate_negative) {
    s21_decimal val, res, expected;
    s21_from_int_to_decimal(-456, &val);
    s21_from_int_to_decimal(456, &expected);
    s21_negate(val, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

START_TEST(negate_zero) {
    s21_decimal val, res, expected;
    s21_from_int_to_decimal(0, &val);
    s21_from_int_to_decimal(0, &expected);
    set_sign(&expected); // Expect -0
    s21_negate(val, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
    ck_assert_int_eq(get_sign(res), 1);
}
END_TEST

START_TEST(negate_float) {
    s21_decimal val, res, expected;
    s21_from_float_to_decimal(123.45f, &val);
    s21_from_float_to_decimal(-123.45f, &expected);
    s21_negate(val, &res);
    ck_assert_int_eq(s21_is_equal(res, expected), 1);
}
END_TEST

Suite * s21_test_negate(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("s21_negate");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, negate_positive);
    tcase_add_test(tc_core, negate_negative);
    tcase_add_test(tc_core, negate_zero);
    tcase_add_test(tc_core, negate_float);
    suite_add_tcase(s, tc_core);

    return s;
}
