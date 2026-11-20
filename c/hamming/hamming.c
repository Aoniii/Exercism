#include <stddef.h>
#include <string.h>
#include "hamming.h"

int compute(const char *lhs, const char *rhs) {
	if (!lhs || !rhs)
		return (-1);

	size_t size = strlen(lhs);
	if (size != strlen(rhs))
		return (-1);

	int i = 0;
	while (size) {
		if (*lhs++ != *rhs++)
			i++;
		size--;
	}
	return (i);
}
