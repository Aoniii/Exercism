#include <stddef.h>
#include <stdint.h>
#include "matching_brackets.h"

bool is_paired(const char *input) {
	uint8_t idx = 0;
	type_t	buffer[BUFFER_SIZE];

	for (size_t i = 0; input[i]; i++) {
		if (input[i] == '[')
			buffer[idx++] = BRACKET;
		else if (input[i] == '{')
			buffer[idx++] = BRACE;
		else if (input[i] == '(')
			buffer[idx++] = PARENTHESE;
		else if (input[i] == ']') {
			if (idx == 0 || buffer[idx - 1] != BRACKET)
				return (false);
			idx--;
		} else if (input[i] == '}') {
			if (idx == 0 || buffer[idx - 1] != BRACE)
				return (false);
			idx--;
		} else if (input[i] == ')') {
			if (idx == 0 || buffer[idx - 1] != PARENTHESE)
				return (false);
			idx--;
		}
	}

	if (idx == 0)
		return (true);
	return (false);
}
