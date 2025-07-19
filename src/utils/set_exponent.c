#include "../s21_decimal.h"
#include <stdlib.h>

// 0000 0000  0000 0000   0000 0000  0000 0000
// |    unused part   |   |exponent|         | sign bit

int set_exponent(s21_decimal *number, int exponent){
    if(number == NULL) return 1;
    if(exponent < 0 || exponent > 28) return 2;

    number->bits[3] &= 0b10000000000000000000000000000000; //just dont mess with sign bit
    number->bits[3] |= exponent << 16;

    return 0;
}
