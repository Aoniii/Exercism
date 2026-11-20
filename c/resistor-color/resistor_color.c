#include "resistor_color.h"

int color_code(resistor_band_t resistor_band) {
	return (resistor_band);
}

const resistor_band_t *colors() {
	static const resistor_band_t resistor[10] = {
		BLACK,
		BROWN,
		RED,
		ORANGE,
		YELLOW,
		GREEN,
		BLUE,
		VIOLET,
		GREY,
		WHITE
	};

	return (resistor);
}
