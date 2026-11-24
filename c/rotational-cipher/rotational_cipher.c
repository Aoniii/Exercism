#include <stdlib.h>
#include <string.h>
#include "rotational_cipher.h"

char *rotate(const char *text, int shift_key) {
	char *str = malloc(strlen(text) + 1);
	if (!str)
		return (0);

	int i = 0;
	for (; *text; text++, i++) {
		if ((*text | 0x20) >= 'a' && (*text | 0x20) <= 'z') {
			str[i] = ('A' + ((*text & ~0x20) - 'A' + shift_key) % 26) |
				(*text & 0x20);
		} else {
			str[i] = *text;
		}
	}
	str[i] = 0;
	return (str);
}
