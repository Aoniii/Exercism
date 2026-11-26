#include <stdlib.h>
#include "spiral_matrix.h"

static const int	dx[4] = {1, 0, -1, 0};
static const int	dy[4] = {0, 1, 0, -1};

static spiral_matrix_t *spiral_matrix_alloc(int size) {
	spiral_matrix_t *spiral = malloc(sizeof(spiral_matrix_t));
	if (!spiral)
		return (0);

	spiral->size = size;
	if (size == 0) {
		spiral->matrix = 0;
		return (spiral);
	}

	spiral->matrix = malloc(sizeof(int *) * size);
	if (!spiral->matrix) {
		free(spiral);
		return (0);
	}

	for (int i = 0; i < spiral->size; i++) {
		spiral->matrix[i] = calloc(size, sizeof(int));
		if (!spiral->matrix[i]) {
			spiral->size = i;
			spiral_matrix_destroy(spiral);
			return (0);
		}
	}

	return (spiral);
}

spiral_matrix_t *spiral_matrix_create(int size) {
	spiral_matrix_t *spiral = spiral_matrix_alloc(size);
	if (!spiral)
		return (0);

	int x = 0;
	int y = 0;
	int dir = 0;
	for (int i = 1; i <= size * size; i++) {
		spiral->matrix[y][x] = i;

		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= size || ny < 0 || ny >= size ||
			spiral->matrix[ny][nx] != 0) {
			dir = (dir + 1) % 4;
			nx = x + dx[dir];
			ny = y + dy[dir];
		}
		x = nx;
		y = ny;
	}

	return (spiral);
}

void spiral_matrix_destroy(spiral_matrix_t *spiral) {
	if (!spiral)
		return;

	for (int i = 0; i < spiral->size; i++)
		free(spiral->matrix[i]);
	free(spiral->matrix);
	free(spiral);
}
