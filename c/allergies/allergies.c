#include "allergies.h"

bool is_allergic_to(allergen_t allergen, int score) {
	return (score & (1u << allergen));
}

allergen_list_t get_allergens(int score) {
	allergen_list_t list = {
		.count = 0,
	};

	for (int i = 0; i < ALLERGEN_COUNT; i++) {
		if (score & (1u << i)) {
			list.allergens[i] = true;
			list.count++;
		}
	}

	return (list);
}
