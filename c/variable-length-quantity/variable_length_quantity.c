#include "variable_length_quantity.h"

static void reverse(uint8_t *output, size_t start, size_t end) {
	size_t	left = start;
	size_t	right = end - 1;
	uint8_t tmp;

	while (left < right) {
		tmp = output[left];
		output[left] = output[right];
		output[right] = tmp;
		left++;
		right--;
	}
}

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output) {
	size_t	i = 0;
	size_t	start;

	for (size_t j = 0; j < integers_len; j++) {
		uint32_t k = integers[j];
		start = i;
		output[i++] = k & 0x7F;
		k >>= 7;
		while (k > 0) {
			output[i++] = 0x80 | (k & 0x7F);
			k >>= 7;
		}
		reverse(output, start, i);
	}

	return (i);
}

int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output) {
	if (buffer_len > 0 && (bytes[buffer_len - 1] & 0x80))
		return (-1);

	size_t		i = 0;
	uint32_t	k = 0;
	for (size_t j = 0; j < buffer_len; j++) {
		k = (k << 7) | (bytes[j] & 0x7F);
		if (!(bytes[j] & 0x80)) {
			output[i++] = k;
			k = 0;
		}
	}

	return (i);
}
