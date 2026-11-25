#include "prime_factors.h"

static bool is_prime_u64(uint64_t n) {
	if (n < 2)
		return (false);
	if (n == 2 || n == 3)
		return (true);
	if (n % 2 == 0 || n % 3 == 0)
		return (false);

	for (uint64_t i = 5; i <= n / i; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0)
			return (false);
	}
	return (true);
}

static uint64_t next_prime(uint64_t p) {
	if (p < 2)
		return (2);

	uint64_t candidate = (p % 2 == 0) ? p + 1 : p + 2;
	while (candidate != UINT64_MAX && !is_prime_u64(candidate)) {
		if (candidate > UINT64_MAX - 2)
			return (0);
		candidate += 2;
	}
	return (candidate);
}

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]) {
	if (n < 2)
		return (0);

	uint64_t primes = 2;

	uint64_t i = 0;
	for (uint64_t j = 0; j < UINT64_MAX; j++) {
		while (n % primes == 0) {
			if (i >= MAXFACTORS)
				return (0);
			factors[i++] = primes;
			n /= primes;
			if (n == 1)
				return (i);
		}
		primes = next_prime(primes);
	}
	return (i);
}
