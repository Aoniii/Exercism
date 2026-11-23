#include <time.h>
#include "gigasecond.h"

void gigasecond(time_t input, char *output, size_t size) {
	time_t		after = input + 1000000000;
	struct tm	*time = gmtime(&after);
	strftime(output, size, "%Y-%m-%d %H:%M:%S", time);
}
