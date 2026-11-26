#include "kindergarten_garden.h"

static const char map[256] = {
	['G'] = GRASS,
	['C'] = CLOVER,
	['R'] = RADISHES,
	['V'] = VIOLETS
};

static const char *name[] = {
	"Alice", "Bob", "Charlie", "David", "Eve", "Fred", "Ginny", "Harriet",
	"Ileana", "Joseph", "Kincaid", "Larry", 0
};

plants_t plants(const char *diagram, const char *student) {
	plants_t p = { .plants = {0} };

	uint8_t i = 0;
	for (; name[i]; i++)
		if (strcmp(name[i], student) == 0)
			break;

	const char	*row1 = diagram;
	const char	*row2 = strchr(diagram, '\n') + 1;
	p.plants[0] = map[(unsigned char)row1[i * 2]];
	p.plants[1] = map[(unsigned char)row1[i * 2 + 1]];
	p.plants[2] = map[(unsigned char)row2[i * 2]];
	p.plants[3] = map[(unsigned char)row2[i * 2 + 1]];
	return (p);
}
