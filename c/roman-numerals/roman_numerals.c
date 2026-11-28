#include "roman_numerals.h"

static const uint16_t	values[] = {
	1000, 900, 500, 400, 100, 90, 50,40, 10, 9, 5, 4, 1
};
static const char		*symbols[] = {
	"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
};

char *to_roman_numeral(uint16_t number) {
	uint16_t	cpy = number;
	uint16_t	size = 0;

	for (uint16_t i = 0; i < 13; i++) {
		while (cpy >= values[i]) {
			size += strlen(symbols[i]);
			cpy -= values[i];
		}
	}

	char *roman = malloc(size + 1);
	if (!roman)
		return (0);

	cpy = number;
	roman[0] = 0;
	for (uint16_t i = 0; i < 13; i++) {
		while (cpy >= values[i]) {
			strcat(roman, symbols[i]);
			cpy -= values[i];
		}
	}
	return (roman);
}
