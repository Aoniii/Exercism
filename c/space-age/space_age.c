#include "space_age.h"

static const float PERIODS[PLANET_COUNT] = {
	[MERCURY] = 0.2408467f,
	[VENUS] = 0.61519726f,
	[EARTH] = 1.0f,
	[MARS] = 1.8808158f,
	[JUPITER] = 11.862615f,
	[SATURN] = 29.447498f,
	[URANUS] = 84.016846f,
	[NEPTUNE] = 164.79132f
};

float age(planet_t planet, int64_t seconds) {
	if ((int)planet < MERCURY || planet > NEPTUNE)
		return (-1);
	return ((seconds / 31557600 / PERIODS[planet]));
}
