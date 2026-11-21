#include <stdlib.h>
#include "dnd_character.h"

int ability(void) {
	int result = 0;
	int min;
	int r;

	for (int i = 0; i < 4; i++) {
		r = rand() % 6 + 1;
		if (i == 0) min = r;
		if (r < min) min = r;
		result += r;
	}
	result -= min;
	return (result);
}

int modifier(int score) {
	return ((score - 10 < 0 ? score - 10 - 1 : score - 10) / 2);
}

dnd_character_t make_dnd_character(void) {
	int constitution = ability();
	return ((dnd_character_t){
		ability(),
		ability(),
		constitution,
		ability(),
		ability(),
		ability(),
		10 + modifier(constitution)
	});
}
