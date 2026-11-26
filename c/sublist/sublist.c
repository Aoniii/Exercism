#include "sublist.h"

static bool is_equal(int *a, int *b, size_t a_len, size_t b_len) {
	if (a_len != b_len)
		return (false);
	for (size_t i = 0; i < a_len; i++)
		if (a[i] != b[i])
			return (false);
	return (true);
}

static bool is_sublist(int *a, int *b, size_t a_len, size_t b_len) {
	if (a_len >= b_len)
		return (false);
	for (size_t start = 0; start + a_len <= b_len; start++)
		if (is_equal(a, b + start, a_len, a_len))
			return (true);
	return (false);
}

comparison_result_t check_lists(int *a, int *b, size_t a_len, size_t b_len) {
	if (is_equal(a, b, a_len, b_len))
		return (EQUAL);
	if (is_sublist(a, b, a_len, b_len))
		return (SUBLIST);
	if (is_sublist(b, a, b_len, a_len))
		return (SUPERLIST);
	return (UNEQUAL);
}
