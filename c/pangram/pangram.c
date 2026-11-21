#include <stdint.h>
#include "pangram.h"

bool is_pangram(const char *sentence) {
	if (!sentence)
		return (false);

	const uint32_t	all = (1u << 26) - 1;
	uint32_t		seen = 0;

	for (; *sentence; sentence++) {
		unsigned idx = (unsigned)((*sentence | 0x20) - 'a');
		if (idx < 26) {
			seen |= 1u << idx;
			if (seen == all)
				return (true);
		}
	}

	return (false);
}
