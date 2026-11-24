#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "reverse_string.h"

char *reverse(const char *value) {
	if (!value)
		return (0);

	size_t	i = strlen(value);
	char	*str = malloc(i + 1);
	if (!str)
		return (0);

	if (i <= 0) {
		str[0] = 0;
		return (str);
	}
	str[i--] = 0;

	for (size_t j = 0; j <= i; j++, i--) {
		str[j] = value[i];
		if (i < 1)
			break;
		str[i] = value[j];
	}

	return (str);
}
