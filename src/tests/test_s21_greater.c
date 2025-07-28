#include "../s21_decimal.h"
#include <check.h>

START_TEST(greater_pos) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(500, &val1);
    s21_from_int_to_decimal(100, &val2);
    ck_assert_int_eq(s21_is_greater(val1, val2), 1);
}
END_TEST

START_TEST(greater_pos_fail) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(100, &val1);
    s21_from_int_to_decimal(500, &val2);
    ck_assert_int_eq(s21_is_greater(val1, val2), 0);
}
END_TEST

START_TEST(greater_neg) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(-100, &val1);
    s21_from_int_to_decimal(-500, &val2);
    ck_assert_int_eq(s21_is_greater(val1, val2), 1);
}
END_TEST

START_TEST(greater_neg_fail) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(-500, &val1);
    s21_from_int_to_decimal(-100, &val2);
    ck_assert_int_eq(s21_is_greater(val1, val2), 0);
}
END_TEST

START_TEST(greater_pos_neg) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(100, &val1);
    s21_from_int_to_decimal(-100, &val2);
    ck_assert_int_eq(s21_is_greater(val1, val2), 1);
}
END_TEST

START_TEST(greater_neg_pos) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(-100, &val1);
    s21_from_int_to_decimal(100, &val2);
    ck_assert_int_eq(s21_is_greater(val1, val2), 0);
}
END_TEST

START_TEST(greater_pos_zero) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(100, &val1);
    s21_from_int_to_decimal(0, &val2);
    ck_assert_int_eq(s21_is_greater(val1, val2), 1);
}
END_TEST

START_TEST(greater_neg_zero) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(-100, &val1);
    s21_from_int_to_decimal(0, &val2);
    ck_assert_int_eq(s21_is_greater(val1, val2), 0);
}
END_TEST

START_TEST(greater_zero_pos) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(0, &val1);
    s21_from_int_to_decimal(100, &val2);
    ck_assert_int_eq(s21_is_greater(val1, val2), 0);
}
END_TEST

START_TEST(greater_zero_neg) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(0, &val1);
    s21_from_int_to_decimal(-100, &val2);
    ck_assert_int_eq(s21_is_greater(val1, val2), 1);
}
END_TEST

START_TEST(greater_equal_numbers) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(100, &val1);
    s21_from_int_to_decimal(100, &val2);
    ck_assert_int_eq(s21_is_greater(val1, val2), 0);
}
END_TEST

START_TEST(greater_different_exp) {
    s21_decimal val1, val2;
    s21_from_float_to_decimal(123.456, &val1);
    s21_from_float_to_decimal(123.45, &val2);
    ck_assert_int_eq(s21_is_greater(val1, val2), 1);
}
END_TEST

Suite * s21_test_is_greater(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("s21_is_greater");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, greater_pos);
    tcase_add_test(tc_core, greater_pos_fail);
    tcase_add_test(tc_core, greater_neg);
    tcase_add_test(tc_core, greater_neg_fail);
    tcase_add_test(tc_core, greater_pos_neg);
    tcase_add_test(tc_core, greater_neg_pos);
    tcase_add_test(tc_core, greater_pos_zero);
    tcase_add_test(tc_core, greater_neg_zero);
    tcase_add_test(tc_core, greater_zero_pos);
    tcase_add_test(tc_core, greater_zero_neg);
    tcase_add_test(tc_core, greater_equal_numbers);
    tcase_add_test(tc_core, greater_different_exp);
    suite_add_tcase(s, tc_core);

    return s;
}
