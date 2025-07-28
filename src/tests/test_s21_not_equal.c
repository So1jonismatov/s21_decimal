#include "../s21_decimal.h"
#include <check.h>

START_TEST(not_equal_unequal) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(123, &val1);
    s21_from_int_to_decimal(456, &val2);
    ck_assert_int_eq(s21_is_not_equal(val1, val2), 1);
}
END_TEST

START_TEST(not_equal_equal) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(123, &val1);
    s21_from_int_to_decimal(123, &val2);
    ck_assert_int_eq(s21_is_not_equal(val1, val2), 0);
}
END_TEST

START_TEST(not_equal_different_signs) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(123, &val1);
    s21_from_int_to_decimal(-123, &val2);
    ck_assert_int_eq(s21_is_not_equal(val1, val2), 1);
}
END_TEST

START_TEST(not_equal_zeroes) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(0, &val1);
    s21_from_int_to_decimal(0, &val2);
    set_sign(&val2);
    ck_assert_int_eq(s21_is_not_equal(val1, val2), 0);
}
END_TEST

START_TEST(not_equal_different_exp_equal) {
    s21_decimal val1, val2;
    s21_from_float_to_decimal(123.45, &val1);
    s21_from_float_to_decimal(123.450, &val2);
    ck_assert_int_eq(s21_is_not_equal(val1, val2), 0);
}
END_TEST

START_TEST(not_equal_different_exp_unequal) {
    s21_decimal val1, val2;
    s21_from_float_to_decimal(123.45, &val1);
    s21_from_float_to_decimal(123.456, &val2);
    ck_assert_int_eq(s21_is_not_equal(val1, val2), 1);
}
END_TEST

Suite * s21_test_is_not_equal(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("s21_is_not_equal");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, not_equal_unequal);
    tcase_add_test(tc_core, not_equal_equal);
    tcase_add_test(tc_core, not_equal_different_signs);
    tcase_add_test(tc_core, not_equal_zeroes);
    tcase_add_test(tc_core, not_equal_different_exp_equal);
    tcase_add_test(tc_core, not_equal_different_exp_unequal);
    suite_add_tcase(s, tc_core);

    return s;
}
