#include "../s21_decimal.h"
#include <check.h>

START_TEST(less_or_equal_less) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(100, &val1);
    s21_from_int_to_decimal(500, &val2);
    ck_assert_int_eq(s21_is_less_or_equal(val1, val2), 1);
}
END_TEST

START_TEST(less_or_equal_equal) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(100, &val1);
    s21_from_int_to_decimal(100, &val2);
    ck_assert_int_eq(s21_is_less_or_equal(val1, val2), 1);
}
END_TEST

START_TEST(less_or_equal_greater) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(500, &val1);
    s21_from_int_to_decimal(100, &val2);
    ck_assert_int_eq(s21_is_less_or_equal(val1, val2), 0);
}
END_TEST

START_TEST(less_or_equal_neg_less) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(-500, &val1);
    s21_from_int_to_decimal(-100, &val2);
    ck_assert_int_eq(s21_is_less_or_equal(val1, val2), 1);
}
END_TEST

START_TEST(less_or_equal_neg_equal) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(-100, &val1);
    s21_from_int_to_decimal(-100, &val2);
    ck_assert_int_eq(s21_is_less_or_equal(val1, val2), 1);
}
END_TEST

START_TEST(less_or_equal_neg_greater) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(-100, &val1);
    s21_from_int_to_decimal(-500, &val2);
    ck_assert_int_eq(s21_is_less_or_equal(val1, val2), 0);
}
END_TEST

START_TEST(less_or_equal_neg_pos) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(-100, &val1);
    s21_from_int_to_decimal(100, &val2);
    ck_assert_int_eq(s21_is_less_or_equal(val1, val2), 1);
}
END_TEST

START_TEST(less_or_equal_zero_pos) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(0, &val1);
    s21_from_int_to_decimal(100, &val2);
    ck_assert_int_eq(s21_is_less_or_equal(val1, val2), 1);
}
END_TEST

START_TEST(less_or_equal_neg_zero) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(-100, &val1);
    s21_from_int_to_decimal(0, &val2);
    ck_assert_int_eq(s21_is_less_or_equal(val1, val2), 1);
}
END_TEST

START_TEST(less_or_equal_zero_zero) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(0, &val1);
    s21_from_int_to_decimal(0, &val2);
    ck_assert_int_eq(s21_is_less_or_equal(val1, val2), 1);
}
END_TEST

START_TEST(less_or_equal_exp_equal) {
    s21_decimal val1, val2;
    s21_from_float_to_decimal(123.45, &val1);
    s21_from_float_to_decimal(123.450, &val2);
    ck_assert_int_eq(s21_is_less_or_equal(val1, val2), 1);
}
END_TEST

START_TEST(less_or_equal_exp_less) {
    s21_decimal val1, val2;
    s21_from_float_to_decimal(123.45, &val1);
    s21_from_float_to_decimal(123.456, &val2);
    ck_assert_int_eq(s21_is_less_or_equal(val1, val2), 1);
}
END_TEST

Suite * s21_test_is_less_or_equal(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("s21_is_less_or_equal");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, less_or_equal_less);
    tcase_add_test(tc_core, less_or_equal_equal);
    tcase_add_test(tc_core, less_or_equal_greater);
    tcase_add_test(tc_core, less_or_equal_neg_less);
    tcase_add_test(tc_core, less_or_equal_neg_equal);
    tcase_add_test(tc_core, less_or_equal_neg_greater);
    tcase_add_test(tc_core, less_or_equal_neg_pos);
    tcase_add_test(tc_core, less_or_equal_zero_pos);
    tcase_add_test(tc_core, less_or_equal_neg_zero);
    tcase_add_test(tc_core, less_or_equal_zero_zero);
    tcase_add_test(tc_core, less_or_equal_exp_equal);
    tcase_add_test(tc_core, less_or_equal_exp_less);
    suite_add_tcase(s, tc_core);

    return s;
}
