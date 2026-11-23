#include "triangle.h"

static bool is_possible(triangle_t sides) {
	if (sides.a <= 0 || sides.b <= 0 || sides.c <= 0)
		return (false);
	if (sides.a + sides.b < sides.c)
		return (false);
	if (sides.c + sides.b < sides.a)
		return (false);
	if (sides.a + sides.c < sides.b)
		return (false);
	return (true);
}

bool is_equilateral(triangle_t sides) {
	if (!is_possible(sides))
		return (false);
	if (sides.a == sides.b && sides.a == sides.c)
		return (true);
	return (false);
}

bool is_isosceles(triangle_t sides) {
	if (!is_possible(sides))
		return (false);
	if (sides.a == sides.b || sides.b == sides.c || sides.a == sides.c)
		return (true);
	return (false);
}

bool is_scalene(triangle_t sides) {
	if (!is_possible(sides))
		return (false);
	return (!is_isosceles(sides));
}
