#include <stddef.h>
#include <string.h>
#include "luhn.h"

bool luhn(const char *num) {
	unsigned	sum[2] = { 0, 0 };
	size_t		count = 0;

	for (; *num; num++) {
		if (*num == ' ')
			continue;
		unsigned d = (unsigned)(*num - '0');
		if (d > 9)
			return (false);
		unsigned dbl = d * 2 > 9 ? d * 2 - 9 : d * 2;
		sum[count & 1] += dbl;
		sum[!(count & 1)] += d;
		count++;
	}
	return (count > 1 && sum[count & 1] % 10 == 0);
}
