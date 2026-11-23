#include <math.h>
#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t *band) {
	if (!band)
		return ((resistor_value_t){0, 0});

	resistor_value_t resistor;
	resistor.value = (band[0] * 10 + band[1]) * (pow(10, band[2]));
	resistor.unit = OHMS;
	while (resistor.value % 1000 == 0 && resistor.value) {
		resistor.value /= 1000;
		resistor.unit++;
		if (resistor.unit == GIGAOHMS)
			break;
	}

	return (resistor);
}
