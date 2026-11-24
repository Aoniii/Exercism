#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "nucleotide_count.h"

char *count(const char *dna_strand) {
	if (!dna_strand)
		return (0);

	char *str = malloc(64);
	if (!str)
		return (0);
	str[0] = 0;

	uint16_t tab[4] = {0};
	for (int i = 0; dna_strand[i]; i++) {
		if (dna_strand[i] == 'A')
			tab[0]++;
		else if (dna_strand[i] == 'C')
			tab[1]++;
		else if (dna_strand[i] == 'G')
			tab[2]++;
		else if (dna_strand[i] == 'T')
			tab[3]++;
		else
			return (str);
	}

	snprintf(str, 64, "A:%u C:%u G:%u T:%u",
		tab[0], tab[1], tab[2], tab[3]);
	return (str);
}
