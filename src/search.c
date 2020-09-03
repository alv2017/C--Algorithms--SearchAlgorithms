#include <stdlib.h>
#include "search.h"

// Linear Search
int *linear_search(int arr[], int arr_size, int val) {
	int *ptr = NULL;
	for (int i = 0; i < arr_size; i++) {
		if (arr[i] == val) {
			ptr = &arr[i];
		}
	}
	return ptr;
}
