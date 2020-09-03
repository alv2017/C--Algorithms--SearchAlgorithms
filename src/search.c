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

// Binary Search
int *binary_search(int arr[], int arr_size, int val) {
	int *ptr = NULL;
	int start = 0;
	int end = arr_size - 1;

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

	while (low <= high) {
		mid = (int) ( (double)low + (double)(high - low) * (double)(val - arr[low]) / (double) (arr[high] - arr[low]) );
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



