#include "../s21_decimal.h"
#include <check.h>
#include <stdlib.h>
#include <math.h>

#define CK_ASSERT_FLOAT_EQ(val1, val2) \
    ck_assert(fabsf((val1) - (val2)) < 1e-6)

START_TEST(d2f_null_dst) {
    s21_decimal src;
    s21_from_int_to_decimal(123, &src);
    int code = s21_from_decimal_to_float(src, NULL);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(d2f_zero) {
    s21_decimal src;
    float res;
    s21_from_int_to_decimal(0, &src);
    int code = s21_from_decimal_to_float(src, &res);
    ck_assert_int_eq(code, 0);
    CK_ASSERT_FLOAT_EQ(res, 0.0f);
}
END_TEST

START_TEST(d2f_neg_zero) {
    s21_decimal src;
    float res;
    s21_from_int_to_decimal(0, &src);
    set_sign(&src);
    int code = s21_from_decimal_to_float(src, &res);
    ck_assert_int_eq(code, 0);
    CK_ASSERT_FLOAT_EQ(res, -0.0f);
}
END_TEST

START_TEST(d2f_pos_int) {
    s21_decimal src;
    float res;
    s21_from_int_to_decimal(12345, &src);
    int code = s21_from_decimal_to_float(src, &res);
    ck_assert_int_eq(code, 0);
    CK_ASSERT_FLOAT_EQ(res, 12345.0f);
}
END_TEST

START_TEST(d2f_neg_int) {
    s21_decimal src;
    float res;
    s21_from_int_to_decimal(-54321, &src);
    int code = s21_from_decimal_to_float(src, &res);
    ck_assert_int_eq(code, 0);
    CK_ASSERT_FLOAT_EQ(res, -54321.0f);
}
END_TEST

START_TEST(d2f_pos_float) {
    s21_decimal src;
    float res;
    s21_from_int_to_decimal(123456, &src);
    set_exponent(&src, 3);
    int code = s21_from_decimal_to_float(src, &res);
    ck_assert_int_eq(code, 0);
    CK_ASSERT_FLOAT_EQ(res, 123.456f);
}
END_TEST

START_TEST(d2f_neg_float) {
    s21_decimal src;
    float res;
    s21_from_int_to_decimal(-98765, &src);
    set_exponent(&src, 4);
    int code = s21_from_decimal_to_float(src, &res);
    ck_assert_int_eq(code, 0);
    CK_ASSERT_FLOAT_EQ(res, -9.8765f);
}
END_TEST

START_TEST(d2f_max_val) {
    s21_decimal src = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    float res;
    double expected = 79228162514264337593543950335.0;
    int code = s21_from_decimal_to_float(src, &res);
    ck_assert_int_eq(code, 0);
    ck_assert(fabsf(res - (float)expected) / (float)expected < 1e-6);
}
END_TEST

START_TEST(d2f_min_val) {
    s21_decimal src = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    set_sign(&src);
    float res;
    double expected = -79228162514264337593543950335.0;
    int code = s21_from_decimal_to_float(src, &res);
    ck_assert_int_eq(code, 0);
    ck_assert(fabsf(res - (float)expected) / (float)expected < 1e-6);
}
END_TEST

START_TEST(d2f_max_exp) {
    s21_decimal src;
    float res;
    s21_from_int_to_decimal(12345, &src);
    set_exponent(&src, 28);
    int code = s21_from_decimal_to_float(src, &res);
    ck_assert_int_eq(code, 0);
    CK_ASSERT_FLOAT_EQ(res, 1.2345e-24f);
}
END_TEST

START_TEST(d2f_min_nonzero) {
    s21_decimal src = {{1, 0, 0, 0}};
    set_exponent(&src, 28);
    float res;
    int code = s21_from_decimal_to_float(src, &res);
    ck_assert_int_eq(code, 0);
    ck_assert(res > 0 && res < 1e-27);
    CK_ASSERT_FLOAT_EQ(res, 1e-28f);
}
END_TEST

START_TEST(d2f_complex_bits) {
    s21_decimal src = {{0xAAAAAAAA, 0xCCCCCCCC, 0xEEEEEEEE, 0}};
    float res;
    double expected = 0.0;
    expected += (double)0xAAAAAAAA;
    expected += (double)0xCCCCCCCC * pow(2, 32);
    expected += (double)0xEEEEEEEE * pow(2, 64);
    int code = s21_from_decimal_to_float(src, &res);
    ck_assert_int_eq(code, 0);
    ck_assert(fabsf(res - (float)expected) / (float)expected < 1e-6);
}
END_TEST


Suite * s21_test_from_decimal_to_float(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("s21_from_decimal_to_float");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, d2f_null_dst);
    tcase_add_test(tc_core, d2f_zero);
    tcase_add_test(tc_core, d2f_neg_zero);
    tcase_add_test(tc_core, d2f_pos_int);
    tcase_add_test(tc_core, d2f_neg_int);
    tcase_add_test(tc_core, d2f_pos_float);
    tcase_add_test(tc_core, d2f_neg_float);
    tcase_add_test(tc_core, d2f_max_val);
    tcase_add_test(tc_core, d2f_min_val);
    tcase_add_test(tc_core, d2f_max_exp);
    tcase_add_test(tc_core, d2f_min_nonzero);
    tcase_add_test(tc_core, d2f_complex_bits);
    suite_add_tcase(s, tc_core);

    return s;
}
