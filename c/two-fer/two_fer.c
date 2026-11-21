#include <stdio.h>
#include "two_fer.h"

void two_fer(char *buffer, const char *name) {
	snprintf(buffer, 128, "One for %s, one for me.", name ? name : "you");
}
