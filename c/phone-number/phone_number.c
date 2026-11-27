#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "phone_number.h"

#define NUMBER_LENGTH	10
#define INVALID_NUMBER	"0000000000"

static bool is_separator(char c) {
	return (c == ' ' || c == '(' || c == ')' || c == '-' || c == '.'
		   || c == '+');
}

static bool is_valid_nanp(const char *digits) {
	return (digits[0] >= '2' && digits[3] >= '2');
}

char *phone_number_clean(const char *input) {
	char *number = malloc(NUMBER_LENGTH + 1);
	if (!number)
		return (NULL);
	strcpy(number, INVALID_NUMBER);

	char	digits[NUMBER_LENGTH + 1];
	size_t	count = 0;
	for (size_t i = 0; input[i]; i++) {
		if (isdigit((unsigned char)input[i])) {
			if (count == NUMBER_LENGTH + 1)
				return (number);
			digits[count++] = input[i];
		} else if (!is_separator(input[i])) {
			return (number);
		}
	}

	const char *start = digits;
	if (count == NUMBER_LENGTH + 1) {
		if (digits[0] != '1')
			return (number);
		start++;
		count--;
	}

	if (count != NUMBER_LENGTH || !is_valid_nanp(start))
		return (number);

	memcpy(number, start, NUMBER_LENGTH);
	return (number);
}
