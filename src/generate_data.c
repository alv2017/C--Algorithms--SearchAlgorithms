#include <stdio.h>

int *generate_data(int *arr, int arr_size, int start, int step) {
	arr[0] = start;
	for (int i = 1; i < arr_size; i++) {
		arr[i] = arr[i-1] + step;
	}
	return arr;
}
