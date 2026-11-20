#include <math.h>
#include "darts.h"

uint8_t score(coordinate_t coord) {
	float distance = sqrt(coord.x * coord.x + coord.y * coord.y);

	if (distance <= 1)
		return (10);
	if (distance <= 5)
		return (5);
	if (distance <= 10)
		return (1);
	return (0);
}
