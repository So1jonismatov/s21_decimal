#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../s21_decimal.h"
#include "../utils/s21_utils.h"
#include "s21_convertors.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    if (!dst) return 1;
    memset(dst, 0, sizeof(s21_decimal));
    // manashu error joylarida return 1 ligi noaniq

    if (isnan(src)) {
        return 1;
    }
    if (isinf(src) || fabs(src) >= 7.9228162514264337593543950335e+28) {
        return 1;
    }
    if (src == 0.0f || fabsf(src) < 1e-28f) {
        return 1;
    }

    if (src < 0) {
        src = -src;
        set_sign(dst);
    }

    char buffer[50];
    sprintf(buffer, "%.7e", src);

    char *mantissa = strtok(buffer, "e");
    char *exponent = strtok(NULL, "e");

    double mantissa_float = atof(mantissa);
    int exponent_int = atoi(exponent);

    if(strlen(mantissa)>2){

    }

    s21_from_int_to_decimal(mantissa_int, dst);
    set_exponent(dst, abs(exponent_int));

    return 0;
}
