#include "yacht.h"

static int full_house(int value[6]) {
	int result = 0;
	for (int i = 0; i < 6; i++) {
		if (value[i] == 1 || value[i] == 4 || value[i] == 5)
			return (0);
		result += value[i] * (i + 1);
	}
	return (result);
}

static int four_of_a_kind(int value[6]) {
	int result = 0;
	for (int i = 0; i < 6; i++) {
		if (value[i] >= 4)
			result += 4 * (i + 1);
	}
	return (result);
}

static bool is_straight(int value[6], int start) {
	for (int i = 0; i < 5; i++) {
		if (value[start - 1 + i] != 1)
			return (false);
	}
	return (true);
}

static int sum(dice_t dice) {
	int result = 0;
	for (int i = 0; i < 5; i++)
		result += dice.faces[i];
	return (result);
}

static bool is_yatch(int value[6]) {
	for (int i = 0; i < 5; i++) {
		if (value[i] == 5)
			return (true);
	}
	return (false);
}

int score(dice_t dice, category_t category) {
	int value[6] = {0};
	for (int i = 0; i < 5; i++)
		value[dice.faces[i] - 1]++;

	if (category <= SIXES)
		return ((category + 1) * value[category]);
	if (category == FULL_HOUSE)
		return (full_house(value));
	if (category == FOUR_OF_A_KIND)
		return (four_of_a_kind(value));
	if (category == LITTLE_STRAIGHT)
		return (is_straight(value, 1) ? 30 : 0);
	if (category == BIG_STRAIGHT)
		return (is_straight(value, 2) ? 30 : 0);
	if (category == CHOICE)
		return (sum(dice));
	if (category == YACHT)
		return (is_yatch(value) ? 50 : 0);
	return (0);
}
