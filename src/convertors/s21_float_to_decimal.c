#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../s21_decimal.h"

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

    *(strchr(buffer, 'e')) = '\0';

    long int mantissa_int = 0;
    int exponent_int = atoi(exponent);

    int mantissa_length = strlen(mantissa);
    while(*mantissa != '\0') {
        if(*mantissa == '.'){
            mantissa++;
            continue;
        }
        mantissa_int = mantissa_int * 10 + (*mantissa - '0');
        mantissa++;
    }

    if(mantissa_length > 2){
        exponent_int -= mantissa_length - 2;
    }

    s21_from_int_to_decimal(mantissa_int, dst);
    int final_scale = exponent_int;

    while (final_scale < 0) {
        if (multiply_by_10(dst)) {
            return 1;
        }
        final_scale++;
    }

    while (final_scale > 28) {
        divide_by_10(dst);
        final_scale--;
    }

    set_exponent(dst, final_scale);


    return 0;
}
