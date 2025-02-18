#ifndef _VEC_H
#define _VEC_H

#include <stdlib.h>

typedef struct {
	void **alloc;
	size_t length;
	size_t capacity;
} Array;

// Creates a growable array.
Array *array_create();
// Only frees the array and its allocation, its up to you to free anything stored inside.
void array_delete(Array *array);

void *array_get(Array *array, size_t n);

// Will return 1 if the array could not realloc or if `n` was greater than `array->length`.
int array_insert(Array *array, size_t n, void *val);
// Will return 1 if the array could not realloc.
int array_push(Array *array, void *val);

// Removes and returns the value at `n` or NULL if `n` was greater than `array->length`.
void *array_remove(Array *array, size_t n);

#endif
