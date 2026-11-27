#include "saddle_points.h"

static uint8_t get_max_in_row(uint8_t rows, uint8_t columns,
	uint8_t matrix[rows][columns], uint8_t row) {
	uint8_t value = matrix[row][0];
	for (uint8_t col = 1; col < columns; col++)
		if (matrix[row][col] > value)
			value = matrix[row][col];
	return (value);
}

static uint8_t get_min_in_column(uint8_t rows, uint8_t columns,
	uint8_t matrix[rows][columns], uint8_t column) {
	uint8_t value = matrix[0][column];
	for (uint8_t row = 1; row < rows; row++)
		if (matrix[row][column] < value)
			value = matrix[row][column];
	return (value);
}

saddle_points_t *saddle_points(uint8_t rows, uint8_t columns,
	uint8_t matrix[rows][columns]) {
	uint8_t row_max[rows];
	for (uint8_t i = 0; i < rows; i++)
		row_max[i] = get_max_in_row(rows, columns, matrix, i);

	uint8_t column_min[columns];
	for (uint8_t i = 0; i < columns; i++)
		column_min[i] = get_min_in_column(rows, columns, matrix, i);

	size_t count = 0;
	for (uint8_t i = 0; i < rows; i++)
		for (uint8_t j = 0; j < columns; j++)
			if (matrix[i][j] == row_max[i] && matrix[i][j] == column_min[j])
				count++;

	saddle_points_t *saddle_points = malloc(sizeof(saddle_points_t));
	if (!saddle_points)
		return (0);

	saddle_points->count = count;
	saddle_points->points = malloc(sizeof(saddle_point_t) * count);
	if (!saddle_points->points) {
		free(saddle_points);
		return (0);
	}

	size_t idx = 0;
	for (uint8_t i = 0; i < rows; i++) {
		for (uint8_t j = 0; j < columns; j++) {
			if (matrix[i][j] == row_max[i] && matrix[i][j] == column_min[j]) {
				saddle_points->points[idx].row = i + 1;
				saddle_points->points[idx++].column = j + 1;
			}
		}
	}

	return (saddle_points);
}

void free_saddle_points(saddle_points_t *saddle_points) {
	if (saddle_points)
		free(saddle_points->points);
	free(saddle_points);
}
