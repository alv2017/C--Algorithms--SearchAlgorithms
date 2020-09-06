#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *generate_data(int *arr, int arr_size, int start, int step) {
	arr[0] = start;
	for (int i = 1; i < arr_size; i++) {
		arr[i] = arr[i-1] + step;
	}
	return arr;
}

int *generate_random_data(int *arr, int arr_size, int start, int max_step) {
	arr[0] = start;
	srand(time(0));
	int step = 0;
	for (int i = 1; i < arr_size; i++) {
		step = rand() % max_step;
		arr[i] = arr[i-1] + step;
	}
	return arr;
}
