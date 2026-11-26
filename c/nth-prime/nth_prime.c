#include "nth_prime.h"

static bool is_prime(uint32_t n) {
	if (n < 2)
		return (false);
	if (n == 2 || n == 3)
		return (true);
	if (n % 2 == 0 || n % 3 == 0)
		return (false);

	for (uint32_t i = 5; i <= n / i; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0)
			return (false);
	}
	return (true);
}

static uint32_t next_prime(uint32_t p) {
	if (p < 2)
		return (2);

	uint32_t candidate = (p % 2 == 0) ? p + 1 : p + 2;
	while (candidate != UINT32_MAX && !is_prime(candidate)) {
		if (candidate > UINT32_MAX - 2)
			return (0);
		candidate += 2;
	}
	return (candidate);
}

uint32_t nth(uint32_t n) {
	uint32_t i = 0;
	while (n--)
		i = next_prime(i);
	return (i);
}
