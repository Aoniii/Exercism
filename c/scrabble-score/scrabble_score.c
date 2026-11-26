#include "scrabble_score.h"

static const scoring_t scoring[7] = {
	{ .letters = "AEIOULNRST", .value = 1},
	{ .letters = "DG", .value = 2},
	{ .letters = "BCMP", .value = 3},
	{ .letters = "FHVWY", .value = 4},
	{ .letters = "K", .value = 5},
	{ .letters = "JX", .value = 8},
	{ .letters = "QZ", .value = 10},
};

unsigned int score(const char *word) {
	unsigned int result = 0;

	for (uint8_t i = 0; word[i]; i++) {
		char c = word[i] & ~0x20;
		for (uint8_t j = 0; j < 7; j++) {
			for (uint8_t k = 0; scoring[j].letters[k]; k++) {
				if (c == scoring[j].letters[k]) {
					result += scoring[j].value;
					j = 10;
					break;
				}
			}
		}
	}

	return (result);
}
