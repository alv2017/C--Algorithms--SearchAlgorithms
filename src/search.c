#include <stdlib.h>
#include <math.h>
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

// Binary Search
int *binary_search(int arr[], int arr_size, int val) {
	int *ptr = NULL;
	int start = 0;
	int end = arr_size - 1;

	if (val < arr[0] || val > arr[arr_size-1]) {
		return NULL;
	}

	while (start <= end) {
		int mid = (start + end) / 2;
		if (val == arr[mid]) {
			ptr = &arr[mid];
			break;
		}
		if (val > arr[mid]) {
			start = mid+1;
		}
		else if (val < arr[mid]) {
			end = mid -1;
		}
	}
	return ptr;
}

// Interpolation Search
int *interpolation_search(int arr[], int arr_size, int val) {
	int *ptr = NULL;
	int low = 0;
	int high = arr_size - 1;
	int mid = 0;

	if (val < arr[0] || val > arr[arr_size-1]) {
		return NULL;
	}

	while (low <= high) {
		if (low < high) {
		    mid = low + (int) ((double)(high - low) * (double)(val - arr[low]) / (double) (arr[high] - arr[low]));
		}
		else {
			mid = high;
		}
		if (val == arr[mid]) {
			ptr = &arr[mid];
			break;
		}
		else if (val < arr[mid]) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ptr;
}

int *jump_search(int arr[], int arr_size, int val) {
	int *ptr = NULL;
	int step_size = sqrt(arr_size);
	int step = step_size;
	int low = 0;
	int high = arr_size - 1;

	if (val < arr[0] || val > arr[arr_size-1]) {
		return NULL;
	}

	// Jump Search
	for (int i = 1; i < step_size; i++) {
		step = step_size * i;
		if (val < arr[step]) {
			high = step - 1;
			if (high - low > 1000) {
				step_size = (int) sqrt(high - low);
				i = 1;
			}
			else {
				break;
			}
		}
		else if (val == arr[step]) {
			low = step;
			high = step;
			break;
		}
		else {
			low = step + 1;
		}
	}
	// Linear Search
	for (int i = low; i <= high; i++) {
		if (arr[i] == val) {
			ptr = &arr[i];
			break;
		}
	}
	return ptr;
}


