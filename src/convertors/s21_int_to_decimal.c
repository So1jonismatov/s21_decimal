#include "../s21_decimal.h"
#include "../utils/s21_utils.h"
#include <string.h>


int s21_from_int_to_decimal(int src, s21_decimal *dst){
    if (dst == NULL) return 1; // NULL error
    memset(dst, 0, sizeof(s21_decimal)); // hammasiga 0 beramz dastlabki qiymatlarini
    if(src < 0){
        src = -src;
        set_sign(dst);
    }

    dst->bits[0] = src;

    return 0;
}
