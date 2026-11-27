#ifndef CIRCULAR_BUFFER_H
# define CIRCULAR_BUFFER_H

# include <errno.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>

typedef int buffer_value_t;

typedef struct {
	buffer_value_t	*values;
	size_t			capacity;
	size_t			count;
	size_t			head;
}	circular_buffer_t;

int16_t				write(circular_buffer_t *buffer, buffer_value_t value);
int16_t				overwrite(circular_buffer_t *buffer, buffer_value_t value);
int16_t				read(circular_buffer_t *buffer, buffer_value_t *value);
circular_buffer_t	*new_circular_buffer(size_t capacity);
void				delete_buffer(circular_buffer_t *buffer);
void				clear_buffer(circular_buffer_t *buffer);

#endif
