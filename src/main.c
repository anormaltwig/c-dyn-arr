#include "dyn-arr.h"

#include <stdio.h>

int main() {
	Array *array = array_create();

	char *a = "Hello, World!";
	char *b = "Test string do not remove";
	char *c = "12345678910";

	array_push(array, a);
	array_push(array, b);
	array_push(array, c);

	char *something = array_remove(array, 1);
	printf("Removed: %s\n", something);

	char *d = "Twenty Thousand Cardboard Boxes";
	array_insert(array, 1, d);

	for (size_t i = 0; i < array->length; i++) {
		char *str = array_get(array, i);
		printf("%lu: %s\n", i, str);
	}

	array_delete(array);

	return 0;
}
