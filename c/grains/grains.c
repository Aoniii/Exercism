#include "grains.h"

uint64_t square(uint8_t index) {
	uint64_t i = 0;

	if (index > 64)
		return (0);

	while (index > 0) {
		if (i == 0)
			i++;
		else
			i *= 2;
		index--;
	}

	return (i);
}

uint64_t total(void) {
	uint64_t	i = 0;
	uint64_t	j = 64;

	while (j > 0) {
		i += square(j);
		j--;
	}

	return (i);
}
