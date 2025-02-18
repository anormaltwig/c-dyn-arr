#include "dyn-arr.h"

#include <stdio.h>
#include <string.h>

Array *array_create() {
	Array *array = malloc(sizeof(Array));

	array->alloc = NULL;
	array->length = 0;
	array->capacity = 0;

	return array;
}

void array_delete(Array *array) {
	free(array->alloc);
	free(array);
}

void *array_get(Array *array, size_t n) {
	if (n >= array->length) {
		return NULL;
	}

	return array->alloc[n];
}

int ensure_capacity(Array *array, size_t needed) {
	if (needed > array->capacity) {
		size_t new_cap = array->capacity == 0 ? 1 : array->capacity * 2;

		void *new_alloc = realloc(array->alloc, sizeof(void *) * new_cap);
		if (new_alloc == NULL) {
			return 1;
		}
		array->alloc = new_alloc;
		array->capacity = new_cap;
	}

	return 0;
}

int array_insert(Array *array, size_t n, void *val) {
	if (n > array->length) {
		return 1;
	}

	if (ensure_capacity(array, array->length + 1)) {
		return 1;
	}

	for (size_t i = n; i < array->length; i++) {
		array->alloc[i + 1] = array->alloc[i];
	}

	array->alloc[n] = val;
	array->length += 1;

	return 0;
}

int array_push(Array *array, void *val) {
	if (ensure_capacity(array, array->length + 1)) {
		return 1;
	}

	array->alloc[array->length] = val;
	array->length += 1;

	return 0;
}

void *array_remove(Array *array, size_t n) {
	if (n >= array->length) {
		return NULL;
	}

	void *val = array->alloc[n];

	array->length -= 1;
	for (size_t i = n; i < array->length; i++) {
		array->alloc[i] = array->alloc[i + 1];
	}

	return val;
}
