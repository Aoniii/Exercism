#include <stdlib.h>
#include "circular_buffer.h"

int16_t write(circular_buffer_t *buffer, buffer_value_t value) {
	if (buffer->count == buffer->capacity) {
		errno = ENOBUFS;
		return (EXIT_FAILURE);
	}

	size_t idx = (buffer->head + buffer->count) % buffer->capacity;
	buffer->values[idx] = value;
	buffer->count++;
	return (EXIT_SUCCESS);
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value) {
	if (buffer->count == buffer->capacity) {
		buffer->values[buffer->head] = value;
		buffer->head++;
		if (buffer->head == buffer->capacity)
			buffer->head = 0;
		return (EXIT_SUCCESS);
	}

	return (write(buffer, value));
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *value) {
	if (buffer->count == 0) {
		errno = ENODATA;
		return (EXIT_FAILURE);
	}

	*value = buffer->values[buffer->head];
	buffer->head++;
	if (buffer->head == buffer->capacity)
		buffer->head = 0;
	buffer->count--;
	return (EXIT_SUCCESS);
}

circular_buffer_t *new_circular_buffer(size_t capacity) {
	circular_buffer_t *buffer = malloc(sizeof(circular_buffer_t));
	if (!buffer)
		return (0);

	buffer->values = malloc(sizeof(buffer_value_t) * capacity);
	if (!buffer->values) {
		free(buffer);
		return (0);
	}

	buffer->capacity = capacity;
	buffer->count = 0;
	buffer->head = 0;
	return (buffer);
}

void delete_buffer(circular_buffer_t *buffer) {
	free(buffer->values);
	free(buffer);
}

void clear_buffer(circular_buffer_t *buffer) {
	buffer->count = 0;
	buffer->head = 0;
}
