#include "acronym.h"

static bool is_acronym(char letter, char prev) {
	if (!prev)
		return (true);
	if (!isalpha(letter))
		return (false);
	if (prev != ' ' && prev != '-' && prev != '_')
		return (false);
	return (true);
}

char *abbreviate(const char *phrase) {
	if (!phrase || !phrase[0])
		return (0);

	uint8_t count = 0;
	for (int16_t i = 0; phrase[i]; i++)
		if (is_acronym(phrase[i], (i - 1 >= 0 ? phrase[i - 1] : 0)))
			count++;

	char *acronym = malloc(sizeof(char) * count + 1);
	if (!acronym)
		return (0);

	uint8_t idx = 0;
	for (int16_t i = 0; phrase[i]; i++)
		if (is_acronym(phrase[i], (i - 1 >= 0 ? phrase[i - 1] : 0)))
			acronym[idx++] = phrase[i] & ~0x20;

	acronym[idx] = 0;
	return (acronym);
}
