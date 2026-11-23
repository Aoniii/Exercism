#include <stddef.h>
#include "sum_of_multiples.h"

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
	const unsigned int limit) {
	size_t result = 0;

	for (unsigned int n = 1; n < limit; n++) {
		for (size_t i = 0; i < number_of_factors; i++) {
			if (!factors[i]) continue;
			if (n % factors[i] == 0) {
				result += n;
				break;
			}
		}
	}

	return (result);
}
