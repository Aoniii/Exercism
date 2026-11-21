#include <stddef.h>
#include "binary.h"

int convert(const char *input) {
	int i = 0;

	for (; *input; input++) {
		unsigned digit = *input - '0';
		if (digit > 1)
			return (INVALID);
		i = (i << 1) | digit;
	}

	return (i);
}
