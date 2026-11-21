#include <stdio.h>
#include "raindrops.h"

void convert(char result[], int drops) {
	if (drops % 3 == 0 || drops % 5 == 0 || drops % 7 == 0)
		snprintf(result, 32, "%s%s%s",
			drops % 3 == 0 ? "Pling" : "",
			drops % 5 == 0 ? "Plang" : "",
			drops % 7 == 0 ? "Plong" : ""
			);
	else
		snprintf(result, 32, "%i", drops);
}
