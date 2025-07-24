#include "../s21_decimal.h"

int get_bit(s21_decimal d, int index) {
    if (index < 0 || index > 95) return 0;
    return (d.bits[index / 32] >> (index % 32)) & 1;
}
