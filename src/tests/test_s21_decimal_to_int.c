#include "../s21_decimal.h"
#include <check.h>
#include <stdlib.h>
#include <limits.h>

START_TEST(d2i_null_dst) {
    s21_decimal src;
    s21_from_int_to_decimal(1, &src);
    int code = s21_from_decimal_to_int(src, NULL);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(d2i_zero) {
    s21_decimal src;
    int res = 0;
    s21_from_int_to_decimal(0, &src);
    int code = s21_from_decimal_to_int(src, &res);
    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(d2i_pos) {
    s21_decimal src;
    int res = 0;
    s21_from_int_to_decimal(12345, &src);
    int code = s21_from_decimal_to_int(src, &res);
    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(res, 12345);
}
END_TEST

START_TEST(d2i_neg) {
    s21_decimal src;
    int res = 0;
    s21_from_int_to_decimal(-54321, &src);
    int code = s21_from_decimal_to_int(src, &res);
    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(res, -54321);
}
END_TEST

START_TEST(d2i_truncate_pos) {
    s21_decimal src;
    int res = 0;
    s21_from_float_to_decimal(123.987, &src);
    int code = s21_from_decimal_to_int(src, &res);
    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(res, 123);
}
END_TEST

START_TEST(d2i_truncate_neg) {
    s21_decimal src;
    int res = 0;
    s21_from_float_to_decimal(-987.123, &src);
    int code = s21_from_decimal_to_int(src, &res);
    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(res, -987);
}
END_TEST

START_TEST(d2i_int_max) {
    s21_decimal src;
    int res = 0;
    src.bits[0] = INT_MAX;
    src.bits[1] = 0;
    src.bits[2] = 0;
    src.bits[3] = 0;
    int code = s21_from_decimal_to_int(src, &res);
    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(res, INT_MAX);
}
END_TEST

START_TEST(d2i_int_min) {
    s21_decimal src;
    int res = 0;
    src.bits[0] = (unsigned)INT_MAX + 1;
    src.bits[1] = 0;
    src.bits[2] = 0;
    src.bits[3] = 0;
    set_sign(&src);
    int code = s21_from_decimal_to_int(src, &res);
    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(res, INT_MIN);
}
END_TEST

START_TEST(d2i_overflow_pos) {
    s21_decimal src;
    int res = 0;
    src.bits[0] = (unsigned)INT_MAX + 1;
    src.bits[1] = 0;
    src.bits[2] = 0;
    src.bits[3] = 0;
    int code = s21_from_decimal_to_int(src, &res);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(d2i_overflow_neg) {
    s21_decimal src;
    int res = 0;
    src.bits[0] = (unsigned)INT_MAX + 2;
    src.bits[1] = 0;
    src.bits[2] = 0;
    src.bits[3] = 0;
    set_sign(&src);
    int code = s21_from_decimal_to_int(src, &res);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(d2i_overflow_large) {
    s21_decimal src;
    int res = 0;
    src.bits[0] = 123;
    src.bits[1] = 1; // Non-zero middle bits
    src.bits[2] = 0;
    src.bits[3] = 0;
    int code = s21_from_decimal_to_int(src, &res);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(d2i_scaled_val) {
    s21_decimal src;
    int res = 0;
    s21_from_int_to_decimal(12345, &src);
    set_exponent(&src, 2);
    int code = s21_from_decimal_to_int(src, &res);
    ck_assert_int_eq(code, 0);
    ck_assert_int_eq(res, 123);
}
END_TEST


Suite * s21_test_from_decimal_to_int(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("s21_from_decimal_to_int");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, d2i_null_dst);
    tcase_add_test(tc_core, d2i_zero);
    tcase_add_test(tc_core, d2i_pos);
    tcase_add_test(tc_core, d2i_neg);
    tcase_add_test(tc_core, d2i_truncate_pos);
    tcase_add_test(tc_core, d2i_truncate_neg);
    tcase_add_test(tc_core, d2i_int_max);
    tcase_add_test(tc_core, d2i_int_min);
    tcase_add_test(tc_core, d2i_overflow_pos);
    tcase_add_test(tc_core, d2i_overflow_neg);
    tcase_add_test(tc_core, d2i_overflow_large);
    tcase_add_test(tc_core, d2i_scaled_val);
    suite_add_tcase(s, tc_core);

    return s;
}
