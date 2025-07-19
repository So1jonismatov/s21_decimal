#include "../s21_decimal.h"
#include <stdlib.h>

int unset_sign(s21_decimal * number){
    if(number == NULL){
        return 1; // error
    }

    number->bits[3] &= ((unsigned int) 0); // Bitmask shu yerda qilamz

    return 0; // OK
}