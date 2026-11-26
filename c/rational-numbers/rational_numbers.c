#include "rational_numbers.h"

rational_t add(rational_t r1, rational_t r2) {
	rational_t r;
	r.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
	r.denominator = r1.denominator * r2.denominator;
	return (reduce(r));
}

rational_t subtract(rational_t r1, rational_t r2) {
	rational_t r;
	r.numerator = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
	r.denominator = r1.denominator * r2.denominator;
	return (reduce(r));
}

rational_t multiply(rational_t r1, rational_t r2) {
	rational_t r;
	r.numerator = r1.numerator * r2.numerator;
	r.denominator = r1.denominator * r2.denominator;
	return (reduce(r));
}

rational_t divide(rational_t r1, rational_t r2) {
	rational_t r;
	r.numerator = r1.numerator * r2.denominator;
	r.denominator = r1.denominator * r2.numerator;
	return (reduce(r));
}

rational_t absolute(rational_t r) {
	r.numerator = abs(r.numerator);
	r.denominator = abs(r.denominator);
	return (reduce(r));
}

rational_t exp_rational(rational_t r, int16_t n) {
	if (n < 0) {
		int i = r.numerator;
		r.numerator = pow(r.denominator, abs(n));
		r.denominator = pow(i, abs(n));
	} else {
		r.numerator = pow(r.numerator, n);
		r.denominator = pow(r.denominator, n);
	}
	return (reduce(r));
}

float exp_real(int16_t x, rational_t r) {
	return (powf(x, (float)r.numerator / r.denominator));
}

rational_t reduce(rational_t r) {
	int i = r.numerator;
	int j = r.denominator;
	int k;

	while (j != 0) {
		k = i % j;
		i = j;
		j = k;
	}

	if (i < 0)
		i *= -1;

	r.numerator /= i;
	r.denominator /= i;

	if (r.denominator < 0) {
		r.numerator = -r.numerator;
		r.denominator = -r.denominator;
	}
	return (r);
}
