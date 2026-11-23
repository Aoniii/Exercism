#include <stdint.h>
#include "isogram.h"

bool is_isogram(const char phrase[]) {
	if (!phrase)
		return (false);

	uint32_t seen = 0;

	for (; *phrase; phrase++) {
		unsigned idx = (unsigned)((*phrase | 0x20) - 'a');
		if (idx < 26) {
			if (seen & (1u << idx))
				return (false);
			seen |= 1u << idx;
		}
	}

	return (true);
}
