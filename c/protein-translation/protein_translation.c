#include <string.h>
#include "protein_translation.h"

static const translate_t translate[] = {
	{{"AUG"}, Methionine},
	{{"UUU", "UUC"}, Phenylalanine},
	{{"UUA", "UUG"}, Leucine},
	{{"UCU", "UCC", "UCA", "UCG"}, Serine},
	{{"UAU", "UAC"}, Tyrosine},
	{{"UGU", "UGC"}, Cysteine},
	{{"UGG"}, Tryptophan},
	{{"UAA", "UAG", "UGA"}, -1},
};

protein_t protein(const char *const rna) {
	protein_t prot = {
		.valid = true,
		.count = 0,
		.amino_acids = {0},
	};

	char cpy[3];
	for (size_t i = 0; rna[i];) {
		if (strlen(&rna[i]) < 3) {
			prot.valid = false;
			return (prot);
		}

		strncpy(cpy, &rna[i], 3);
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 4 && translate[j].src[k]; k++) {
				if (strncmp(translate[j].src[k], cpy, 3) == 0) {
					if (translate[j].amino_acid == -1)
						return (prot);
					prot.amino_acids[i / 3] = translate[j].amino_acid;
					prot.count++;
					j = 8;
					break;
				}
			}
		}
		i += 3;
	}

	if (prot.count == 0 && strlen(rna))
		prot.valid = false;
	return (prot);
}
