#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rna_transcription.h"

char *to_rna(const char *dna) {
	static const char map[256] = {
		['G'] = 'C', ['C'] = 'G', ['T'] = 'A', ['A'] = 'U'
	};

	if (!dna)
		return (0);

	size_t	len = strlen(dna);
	char	*rna = malloc(len + 1);
	if (!rna)
		return (0);

	for (size_t i = 0; i < len; i++)
		rna[i] = map[(unsigned char)dna[i]];
	rna[len] = 0;

	return (rna);
}
