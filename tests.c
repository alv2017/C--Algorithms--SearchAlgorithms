#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "src/generate_data.h"
#include "src/code_timing.h"
#include "src/search.h"

#define ARR_SIZE 25
#define START 0
#define STEP 1
#define START_NONEXISTENT 1

int test( int *(*search_algorithm)(int *arr, int arr_size, int val),
		  int *arr, int *existing_points, int *nonexisting_points, int arr_size
		);

int main(void) {
	int arr[ARR_SIZE] = {0};
	generate_data(arr, ARR_SIZE, START, 2*STEP);

	int nonexisting_points[ARR_SIZE] = {0};
	generate_data(nonexisting_points, ARR_SIZE, START_NONEXISTENT, 2*STEP);

	puts("Array:");
	for (int i = 0; i < ARR_SIZE; i++) {
		printf("%d ", arr[i]);
	}
	puts("");

	puts("Non Existent Values:");
	for (int i = 0; i < ARR_SIZE; i++) {
		printf("%d ", nonexisting_points[i]);
	}
	puts("");

	// Linear Search Function
	puts("\nLinear Search Function.");
	test( (*linear_search), arr, arr, nonexisting_points, ARR_SIZE);

	// Binary Search Function
	puts("\nBinary Search Function.");
	test( (*binary_search), arr, arr, nonexisting_points, ARR_SIZE);

	// Jump Search Function
	puts("\nJump Search Function.");
	test( (*jump_search), arr, arr, nonexisting_points, ARR_SIZE);


	// Interpolation Search Function
	puts("\nInterpolation Search Function.");
	test( (*interpolation_search), arr, arr, nonexisting_points, ARR_SIZE);

	return 0;
}

int test( int *(*search_algorithm)(int *arr, int arr_size, int val),
		  int *arr, int *existing_points, int *nonexisting_points, int arr_size
		) {
	int passed = 0;
	int failed = 0;
	int *ptr = NULL;

	// Existing Points
	puts("	-> Testing on Existing Points.");
	for (int i = 0; i < ARR_SIZE; i++) {
		ptr = (*search_algorithm)(arr, ARR_SIZE, existing_points[i]);
		if (ptr != NULL){
			passed += 1;
		}
		else {
			failed += 1;
			if (failed == 1) {
				puts("Failed Tests:");
			}
			printf("Test Failed with the test value % d.\n", arr[i]);
		}
	}

	// Non-Existing Points
	puts("	-> Testing on Non-Existing Points.");
	for (int i = 0; i < ARR_SIZE; i++) {
		ptr = (*search_algorithm)(arr, ARR_SIZE, nonexisting_points[i]);
		if (ptr == NULL){
			passed += 1;
		}
		else {
			failed += 1;
			if (failed == 1) {
				puts("Failed Tests:");
			}
			printf("Test Failed with the test value % d.\n", *ptr);
		}
	}

	puts("Summary:");
	printf("Number of tests passed: %d.\n", passed);
	printf("Number of tests failed: %d.\n", failed);
	puts("");

	return failed;
}
