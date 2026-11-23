#include <math.h>
#include "armstrong_numbers.h"

bool is_armstrong_number(int candidate) {
	if (candidate < 0) return (false);
	if (candidate == 0) return (true);

	int power = 0;
	for (int i = candidate; i > 0; i /= 10)
		power++;

	int result = 0;
	for (int i = candidate; i > 0; i /= 10)
		result += pow(i % 10, power);

	return (result == candidate);
}
