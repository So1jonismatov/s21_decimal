#include "test.h"
#include <stdlib.h>
#include <stdio.h>

int run_suite(Suite *s, const char* suite_name) {
    SRunner *sr = srunner_create(s);
    printf("--------------------------------------\n");
    printf("Running Test Suite: %s\n", suite_name);

    srunner_run_all(sr, CK_NORMAL);

    int failed_count = srunner_ntests_failed(sr);
    srunner_free(sr);

    return failed_count;
}

typedef struct {
    Suite* (*func)(void);
    const char* name;
} suite_info;


int main(void) {
    int total_failed = 0;

    suite_info suites[] = {
        {s21_test_add, "s21_add"},
        {s21_test_sub, "s21_sub"},
        {s21_test_mul, "s21_mul"},
        {s21_test_div, "s21_div"},
        {s21_test_is_equal, "s21_is_equal"},
        {s21_test_is_not_equal, "s21_is_not_equal"},
        {s21_test_is_less, "s21_is_less"},
        {s21_test_is_less_or_equal, "s21_is_less_or_equal"},
        {s21_test_is_greater, "s21_is_greater"},
        {s21_test_is_greater_or_equal, "s21_is_greater_or_equal"},
        {s21_test_from_int_to_decimal, "s21_from_int_to_decimal"},
        {s21_test_from_float_to_decimal, "s21_from_float_to_decimal"},
        {s21_test_from_decimal_to_int, "s21_from_decimal_to_int"},
        {s21_test_from_decimal_to_float, "s21_from_decimal_to_float"},
        {s21_test_truncate, "s21_truncate"},
        {s21_test_floor, "s21_floor"},
        {s21_test_round, "s21_round"},
        {s21_test_negate, "s21_negate"}
    };

    int num_suites = sizeof(suites) / sizeof(suites[0]);

    for (int i = 0; i < num_suites; i++) {
        total_failed += run_suite(suites[i].func(), suites[i].name);
    }

    printf("\n==============================\n");
    printf("TOTAL FAILED: %d\n", total_failed);
    printf("==============================\n");

    return 0;
}
