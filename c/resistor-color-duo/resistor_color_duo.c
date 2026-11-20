#include "resistor_color_duo.h"

uint16_t color_code(resistor_band_t *resistor_band) {
	if (!resistor_band)
		return (0);

	return (resistor_band[0] * 10 + resistor_band[1]);
}
