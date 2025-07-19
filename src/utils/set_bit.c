#include "../s21_decimal.h"
#include <stdlib.h>


int set_bit(s21_decimal * number, int i, int j){
    if(number == NULL) return 1; //NULL ref error
    if(i<0 || i>3 || j < 0 || j > 31) return 2; // out of range error

    number->bits[i] |= ((unsigned int) 1 << j); // -> shu yerda i-element ni j-chi bitini set qilamz

    return 0; // success

}
