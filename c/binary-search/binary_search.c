#include <stddef.h>
#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length) {
	if (!length || !arr)
		return (0);

	size_t		half = length / 2;
	const int	*mid = arr + half;

	if (*mid == value)
		return (mid);
	if (*mid > value)
		return (binary_search(value, arr, half));
	return (binary_search(value, mid + 1, length - half - 1));
}
