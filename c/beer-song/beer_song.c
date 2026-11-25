#include <stdio.h>
#include "beer_song.h"

void recite(uint8_t start_bottles, uint8_t take_down, char **song) {
	uint8_t		nb_bottles = start_bottles;
	uint16_t	lines = 0;

	for (uint8_t i = 0; i < take_down; i++) {
		if (lines + 3 > MAX_LINE_COUNT)
			return;

		if (lines != 0)
			song[lines++][0] = 0;

		if (nb_bottles == 0) {
			snprintf(song[lines++], MAX_LINE_LENGTH,
				"No more bottles of beer on the wall, no more bottles of beer.");
			snprintf(song[lines++], MAX_LINE_LENGTH,
				"Go to the store and buy some more, 99 bottles of beer on the wall.");
		} else {
			snprintf(song[lines++], MAX_LINE_LENGTH,
				"%u %s of beer on the wall, %u %s of beer.",
				nb_bottles, nb_bottles == 1 ? "bottle" : "bottles",
				nb_bottles, nb_bottles == 1 ? "bottle" : "bottles"
				);
			if (nb_bottles == 1) {
				snprintf(song[lines++], MAX_LINE_LENGTH,
					"Take it down and pass it around, no more bottles of beer on the wall.");
			} else {
				snprintf(song[lines++], MAX_LINE_LENGTH,
					"Take one down and pass it around, %u %s of beer on the wall.",
					nb_bottles - 1, nb_bottles - 1 == 1 ? "bottle" : "bottles"
					);
			}
		}

		nb_bottles = (nb_bottles == 0) ? 99 : nb_bottles - 1;
	}
}
