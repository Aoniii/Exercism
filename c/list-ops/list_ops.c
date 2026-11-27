#include "list_ops.h"

list_t *new_list(size_t length, list_element_t elements[]) {
	list_t *list = malloc(sizeof(list_t) + length * sizeof(list_element_t));
	if (!list)
		return (0);

	list->length = length;
	if (elements)
		for (size_t i = 0; i < length; i++)
			list->elements[i] = elements[i];
	return (list);
}

list_t *append_list(list_t *list1, list_t *list2) {
	list_t *list = new_list(list1->length + list2->length, NULL);
	if (!list)
		return (0);

	for (size_t i = 0; i < list->length; i++) {
		if (i < list1->length)
			list->elements[i] = list1->elements[i];
		else
			list->elements[i] = list2->elements[i - list1->length];
	}
	return (list);
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
	size_t len = 0;
	for (size_t i = 0; i < list->length; i++)
		if (filter(list->elements[i]))
			len++;

	list_t *ret = new_list(len, NULL);
	if (!ret)
		return (0);

	size_t i = 0;
	for (size_t j = 0; j < list->length; j++)
		if (filter(list->elements[j]))
			ret->elements[i++] = list->elements[j];

	return (ret);
}

size_t length_list(list_t *list) {
	return (list->length);
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {
	list_t *ret = new_list(list->length, NULL);
	if (!ret)
		return (0);

	for (size_t i = 0; i < list->length; i++)
		ret->elements[i] = map(list->elements[i]);

	return (ret);
}

list_element_t foldl_list(list_t *list, list_element_t initial,
	list_element_t (*foldl)(list_element_t, list_element_t)) {
	list_element_t value = initial;

	for (size_t i = 0; i < list->length; i++)
		value = foldl(list->elements[i], value);
	return (value);
}

list_element_t foldr_list(list_t *list, list_element_t initial,
	list_element_t (*foldr)(list_element_t, list_element_t)) {
	list_element_t value = initial;

	for (size_t i = 0; i < list->length; i++)
		value = foldr(list->elements[list->length - 1 - i], value);
	return (value);
}

list_t *reverse_list(list_t *list) {
	list_t *ret = new_list(list->length, NULL);
	if (!ret)
		return (0);

	for (size_t i = 0; i < list->length; i++)
		ret->elements[i] = list->elements[list->length - 1 - i];

	return (ret);
}

void delete_list(list_t *list) {
	free(list);
}
