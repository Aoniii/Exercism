#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include "all_your_base.h"

size_t rebase(int8_t digits[DIGITS_ARRAY_SIZE], int16_t input_base,
	int16_t output_base, size_t input_length) {
	if (input_base < 2 || output_base < 2 || input_length == 0)
		return (0);

	int64_t result = 0;
	for (uint8_t i = 0; i < input_length; i++) {
		if (digits[i] < 0 || digits[i] >= input_base)
			return (0);
		result += digits[i] * pow(input_base, input_length - i - 1);
	}

	size_t len = 0;
	do {
		digits[len++] = result % output_base;
		result /= output_base;
	} while (result > 0);

	for (size_t i = 0; i < len / 2; i++) {
		int8_t tmp = digits[i];
		digits[i] = digits[len - 1 - i];
		digits[len - 1 - i] = tmp;
	}

	return (len);
}
