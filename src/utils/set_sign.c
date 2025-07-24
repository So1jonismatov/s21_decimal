#include "../s21_decimal.h"
#include <stdlib.h>

/*
 * @brief s21_decimal arrayni sign(+,-) ga 1 beradi
 */

int set_sign(s21_decimal * number){
    if(number == NULL){
        return 1; // error
    }

    set_bit(number, 3, 31); // Bitmask shu yerda qilamz

    return 0; // OK
}
