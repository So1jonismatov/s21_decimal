#include <limits.h>
#include <stdlib.h>
#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    if (dst == NULL) {
        return 1;
    }

    s21_decimal truncated_val;
    s21_truncate(src, &truncated_val);

    // If any of the higher bits are set, the number is too large to fit in any int.
    if (truncated_val.bits[1] != 0 || truncated_val.bits[2] != 0) {
        return 1; // Conversion error: too large
    }

    int sign = get_sign(src);
    // Treat the bits as a pure magnitude for comparison purposes.
    unsigned int magnitude = truncated_val.bits[0];

    if (sign) {
        // Handle negative numbers. Check for underflow.
        // The magnitude of INT_MIN is ((unsigned int)INT_MAX + 1).
        // If our magnitude is greater than this, it's an error.
        if (magnitude > (unsigned)INT_MAX + 1U) {
            return 1; // Conversion error: too small (underflow)
        }
    } else {
        // Handle positive numbers. Check for overflow.
        // The magnitude of INT_MAX is INT_MAX.
        // If our magnitude is greater than this, it's an error.
        if (magnitude > INT_MAX) {
            return 1; // Conversion error: too large (overflow)
        }
    }

    // If all checks passed, perform the conversion.
    *dst = magnitude;
    if (sign) {
        *dst = -(*dst);
    }

    return 0; // OK
}
