#include "high_scores.h"

int32_t latest(const int32_t *scores, size_t scores_len) {
	if (!scores || !scores_len)
		return (0);
	return (scores[scores_len - 1]);
}

int32_t personal_best(const int32_t *scores, size_t scores_len) {
	if (!scores || !scores_len)
		return (0);

	int32_t highest = INT32_MIN;
	for (size_t i = 0; i < scores_len; i++) {
		if (scores[i] > highest)
			highest = scores[i];
	}
	return (highest);
}

static int swap_if_less(int32_t *output, int i, int j) {
	if (output[i] < output[j]) {
		int32_t t = output[i];
		output[i] = output[j];
		output[j] = t;
		return (1);
	}
	return (0);
}

static void push(int32_t *output, int32_t value) {
	output[2] = value;
	if (swap_if_less(output, 1, 2))
		swap_if_less(output, 0, 1);
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
	int32_t *output) {
	if (!scores || !scores_len)
		return (0);

	output[0] = output[1] = output[2] = INT32_MIN;
	for (size_t i = 0; i < scores_len; i++)
		if (scores[i] > output[2])
			push(output, scores[i]);
	return (scores_len < 3 ? scores_len : 3);
}
