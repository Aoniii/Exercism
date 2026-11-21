#include "eliuds_eggs.h"

unsigned int egg_count(unsigned int decimal) {
	int result = 0;

	while (decimal != 0) {
		if (decimal & 1)
			result++;
		decimal >>= 1;
	}
	return (result);
}
