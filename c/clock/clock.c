#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clock.h"

clock_t clock_create(int hour, int minute) {
	clock_t clock;

	for (; minute >= 60; minute -= 60)
		hour++;
	for (; minute < 0; minute += 60)
		hour--;
	for (; hour >= 24; hour -= 24);
	for (; hour < 0; hour += 24);

	snprintf(clock.text, MAX_STR_LEN, "%02i:%02i", hour, minute);
	return (clock);
}

clock_t clock_add(clock_t clock, int minute_add) {
	int hour = atoi(clock.text);
	int minute = atoi(&clock.text[3]);
	minute += minute_add;
	return (clock_create(hour, minute));
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {
	int hour = atoi(clock.text);
	int minute = atoi(&clock.text[3]);
	minute -= minute_subtract;
	return (clock_create(hour, minute));
}

bool clock_is_equal(clock_t a, clock_t b) {
	return (strcmp(a.text, b.text) == 0);
}
