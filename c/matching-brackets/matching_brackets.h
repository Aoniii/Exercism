#ifndef MATCHING_BRACKETS_H
# define MATCHING_BRACKETS_H

# include <stdbool.h>

# define BUFFER_SIZE	128

typedef enum {
	BRACKET,
	BRACE,
	PARENTHESE,
}	type_t;

bool is_paired(const char *input);

#endif
