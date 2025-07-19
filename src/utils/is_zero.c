#include "../s21_decimal.h"
int is_zero(s21_decimal a){
    return a.bits[0] == 0 && a.bits[1] == 0 && a.bits[2] == 0;
}
