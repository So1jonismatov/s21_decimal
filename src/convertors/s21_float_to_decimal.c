#include "../s21_decimal.h"
#include <math.h>
#include <string.h>

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    // Step 1: Handle error cases and special values
    if (!dst) return 1;
    memset(dst, 0, sizeof(s21_decimal));

    if (isnan(src) || isinf(src)) {
        return 1;
    }

    // Step 2: Handle sign and zero
    if (src == 0.0f) {
        return 0; // dst is already zeroed out
    }

    if (src < 0) {
        set_sign(dst);
        src = -src;
    }

    // Step 3: Check if the number is within the representable range
    if (src > 7.92281625e+28f) { // Max decimal value
        return 1;
    }
    if (src < 1e-28f) {
        return 1;
    }

    // Step 4: Normalize the float and determine the scale
    int scale = 0;
    // Bring the number into a range where it has 7 integer digits
    while (src < 1000000.0f) {
        src *= 10.0f;
        scale++;
    }

    // Perform rounding for the 7th significant digit
    src = roundf(src);

    // If rounding caused overflow, adjust the scale
    while (src >= 10000000.0f) {
        src /= 10.0f;
        scale--;
    }

    // Step 5: Write the resulting integer mantissa to the decimal
    dst->bits[0] = (unsigned int)src;

    // Step 6: Set the final scale
    if (scale > 28) {
        // This case should be rare due to prior checks, but as a safeguard...
        // We must reduce the mantissa until the scale is valid.
        while (scale > 28) {
            divide_by_10(dst);
            scale--;
        }
    }
    set_exponent(dst, scale);

    return 0;
}
