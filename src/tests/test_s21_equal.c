#include "../s21_decimal.h"
#include <check.h>

START_TEST(equal_pos_numbers) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(12345, &val1);
    s21_from_int_to_decimal(12345, &val2);
    ck_assert_int_eq(s21_is_equal(val1, val2), 1);
}
END_TEST

START_TEST(equal_neg_numbers) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(-12345, &val1);
    s21_from_int_to_decimal(-12345, &val2);
    ck_assert_int_eq(s21_is_equal(val1, val2), 1);
}
END_TEST

START_TEST(equal_zero) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(0, &val1);
    s21_from_int_to_decimal(0, &val2);
    ck_assert_int_eq(s21_is_equal(val1, val2), 1);
}
END_TEST

START_TEST(equal_pos_neg_zero) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(0, &val1);
    s21_from_int_to_decimal(0, &val2);
    set_sign(&val2);
    ck_assert_int_eq(s21_is_equal(val1, val2), 1);
}
END_TEST

START_TEST(unequal_numbers) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(12345, &val1);
    s21_from_int_to_decimal(54321, &val2);
    ck_assert_int_eq(s21_is_equal(val1, val2), 0);
}
END_TEST

START_TEST(unequal_signs) {
    s21_decimal val1, val2;
    s21_from_int_to_decimal(12345, &val1);
    s21_from_int_to_decimal(-12345, &val2);
    ck_assert_int_eq(s21_is_equal(val1, val2), 0);
}
END_TEST

START_TEST(equal_different_exp) {
    s21_decimal val1, val2;
    s21_from_float_to_decimal(123.45, &val1);
    s21_from_float_to_decimal(123.450, &val2);
    ck_assert_int_eq(s21_is_equal(val1, val2), 1);
}
END_TEST

START_TEST(equal_max_values) {
    s21_decimal val1, val2;
    val1.bits[0] = 0xFFFFFFFF;
    val1.bits[1] = 0xFFFFFFFF;
    val1.bits[2] = 0xFFFFFFFF;
    val1.bits[3] = 0;
    val2.bits[0] = 0xFFFFFFFF;
    val2.bits[1] = 0xFFFFFFFF;
    val2.bits[2] = 0xFFFFFFFF;
    val2.bits[3] = 0;
    ck_assert_int_eq(s21_is_equal(val1, val2), 1);
}
END_TEST

Suite * s21_test_is_equal(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("s21_is_equal");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, equal_pos_numbers);
    tcase_add_test(tc_core, equal_neg_numbers);
    tcase_add_test(tc_core, equal_zero);
    tcase_add_test(tc_core, equal_pos_neg_zero);
    tcase_add_test(tc_core, unequal_numbers);
    tcase_add_test(tc_core, unequal_signs);
    tcase_add_test(tc_core, equal_different_exp);
    tcase_add_test(tc_core, equal_max_values);
    suite_add_tcase(s, tc_core);

    return s;
}
