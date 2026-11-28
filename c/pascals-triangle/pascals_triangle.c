#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include "pascals_triangle.h"

static uint32_t factorial(uint8_t nb) {
	uint32_t i;

	i = 1;
	if (nb < 2)
		return (1);
	while (nb > 0)
		i *= nb--;
	return (i);
}

static uint8_t calc(uint8_t n, uint8_t k) {
	return (factorial(n) / (factorial(k) * factorial(n - k)));
}

void free_triangle(uint8_t **triangle, size_t rows) {
	for (size_t i = 0; i < rows; i++)
		free(triangle[i]);
	free(triangle);
}

uint8_t **create_triangle(size_t rows) {
	if (rows == 0) {
		uint8_t **empty = malloc(sizeof(*empty));
		if (!empty)
			return (NULL);
		empty[0] = calloc(1, sizeof(**empty));
		if (!empty[0]) {
			free(empty);
			return (NULL);
		}
		return (empty);
	}

	uint8_t **triangle = malloc(sizeof(uint8_t *) * rows);
	if (!triangle)
		return (0);

	for (size_t i = 0; i < rows; i++) {
		triangle[i] = calloc(rows, sizeof(uint8_t));
		if (!triangle[i]) {
			free_triangle(triangle, i);
			return (0);
		}

		for (size_t j = 0; j <= i; j++)
			triangle[i][j] = calc(i, j);
	}

	return (triangle);
}
