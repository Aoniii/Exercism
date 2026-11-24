#include <stdint.h>
#include "square_root.h"

int32_t square_root(int32_t nb) {
	if (nb <= 0)
		return (0);

	int32_t res = 0;;
	int32_t cur = 1 << 30;
	for (; cur > nb; cur >>= 2);
	for (; cur != 0; cur >>= 2) {
		if (nb >= res + cur) {
			nb -= res + cur;
			res = (res >> 1) + cur;
		} else {
			res >>= 1;
		}
	}

	return (res);
}
