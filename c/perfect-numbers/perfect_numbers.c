#include "perfect_numbers.h"

kind classify_number(int number) {
	int aliquote = 0;
	if (number <= 0)
		return (ERROR);

	for (int i = 1; i < number; i++) {
		if (number % i == 0)
			aliquote += i;
	}

	if (number == aliquote)
		return (PERFECT_NUMBER);
	if (number < aliquote)
		return (ABUNDANT_NUMBER);
	if (number > aliquote)
		return (DEFICIENT_NUMBER);

	return (ERROR);
}
