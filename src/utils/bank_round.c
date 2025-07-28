#include <stdlib.h>
#include "../s21_decimal.h"

/**
 * @brief Applies bank rounding to a decimal value.
 *
 * This function rounds a decimal based on the remainder of a division by 10.
 * - If remainder > 5, it rounds up.
 * - If remainder < 5, it truncates (does nothing).
 * - If remainder == 5, it rounds to the nearest even number (rounds up if the
 *   last digit of the value is odd).
 *
 * @param value The decimal number to round.
 * @param remainder The remainder from the preceding division by 10.
 * @return int Returns 1 if rounding causes an overflow, 0 otherwise.
 */
int bank_round(s21_decimal *value, int remainder) {
    if (value == NULL) {
        return 0;
    }

    int overflow = 0;

    // Case 1: Remainder is greater than 5, always round up.
    if (remainder > 5) {
        s21_decimal one = {{1, 0, 0, 0}};
        overflow = add_abs(*value, one, value);
    }
    // Case 2: Remainder is exactly 5, round to the nearest even number.
    else if (remainder == 5) {
        // We check the last bit of the integer part. If it's 1 (odd), we round up.
        // Otherwise (if it's even), we do nothing.
        if (get_bit(*value, 0)) {
            s21_decimal one = {{1, 0, 0, 0}};
            overflow = add_abs(*value, one, value);
        }
    }
    // Case 3: Remainder is less than 5, we round down (truncate), which means
    // we do nothing as the division has already occurred.

    return overflow;
}
