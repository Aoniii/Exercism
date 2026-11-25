#include "sieve.h"

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
	bool *eliminated = calloc(limit + 1, sizeof(bool));
	if (!eliminated)
		return (0);

	eliminated[0] = eliminated[1] = true;
	for (uint32_t i = 2; i <= limit; i++) {
		for (uint32_t j = 2; i * j <= limit; j++) {
			eliminated[i * j] = true;
		}
	}

	uint32_t i = 0;
	for (uint32_t j = 0; j <= limit && i < max_primes; j++) {
		if (eliminated[j] == false)
			primes[i++] = j;
	}

	free(eliminated);
	eliminated = 0;
	return (i);
}
