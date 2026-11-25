#ifndef BEER_SONG_H
# define BEER_SONG_H

# define MAX_LINE_LENGTH	(1024)
# define MAX_LINE_COUNT		(299)

# include <stdint.h>

void recite(uint8_t start_bottles, uint8_t take_down, char **song);

#endif
