#include "../s21_decimal.h"
#include <check.h>

START_TEST(less_pos) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(100, &val1);
    s21_from_int_to_decimal(500, &val2);
    ck_assert_int_eq(s21_is_less(val1, val2), 1);
}
END_TEST

START_TEST(less_pos_fail) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(500, &val1);
    s21_from_int_to_decimal(100, &val2);
    ck_assert_int_eq(s21_is_less(val1, val2), 0);
}
END_TEST

START_TEST(less_neg) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(-500, &val1);
    s21_from_int_to_decimal(-100, &val2);
    ck_assert_int_eq(s21_is_less(val1, val2), 1);
}
END_TEST

START_TEST(less_neg_fail) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(-100, &val1);
    s21_from_int_to_decimal(-500, &val2);
    ck_assert_int_eq(s21_is_less(val1, val2), 0);
}
END_TEST

START_TEST(less_neg_pos) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(-100, &val1);
    s21_from_int_to_decimal(100, &val2);
    ck_assert_int_eq(s21_is_less(val1, val2), 1);
}
END_TEST

START_TEST(less_pos_neg) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(100, &val1);
    s21_from_int_to_decimal(-100, &val2);
    ck_assert_int_eq(s21_is_less(val1, val2), 0);
}
END_TEST

START_TEST(less_zero_pos) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(0, &val1);
    s21_from_int_to_decimal(100, &val2);
    ck_assert_int_eq(s21_is_less(val1, val2), 1);
}
END_TEST

START_TEST(less_neg_zero) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(-100, &val1);
    s21_from_int_to_decimal(0, &val2);
    ck_assert_int_eq(s21_is_less(val1, val2), 1);
}
END_TEST

START_TEST(less_equal_numbers) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(100, &val1);
    s21_from_int_to_decimal(100, &val2);
    ck_assert_int_eq(s21_is_less(val1, val2), 0);
}
END_TEST

START_TEST(less_different_exp_equal) {
    s21_decimal val1, val2;
    s21_from_float_to_decimal(123.45, &val1);
    s21_from_float_to_decimal(123.450, &val2);
    ck_assert_int_eq(s21_is_less(val1, val2), 0);
}
END_TEST

START_TEST(less_different_exp_less) {
    s21_decimal val1, val2;
    s21_from_float_to_decimal(123.45, &val1);
    s21_from_float_to_decimal(123.456, &val2);
    ck_assert_int_eq(s21_is_less(val1, val2), 1);
}
END_TEST

Suite * s21_test_is_less(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("s21_is_less");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, less_pos);
    tcase_add_test(tc_core, less_pos_fail);
    tcase_add_test(tc_core, less_neg);
    tcase_add_test(tc_core, less_neg_fail);
    tcase_add_test(tc_core, less_neg_pos);
    tcase_add_test(tc_core, less_pos_neg);
    tcase_add_test(tc_core, less_zero_pos);
    tcase_add_test(tc_core, less_neg_zero);
    tcase_add_test(tc_core, less_equal_numbers);
    tcase_add_test(tc_core, less_different_exp_equal);
    tcase_add_test(tc_core, less_different_exp_less);
    suite_add_tcase(s, tc_core);

    return s;
}
