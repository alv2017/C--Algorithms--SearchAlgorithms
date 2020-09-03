#include <stdio.h>
#include <time.h>
#include "search.h"

double code_timer( int *arr, int arr_size, int val, int nrun,
		int *(*search_algorithm)(int *arr, int arr_size, int val) )
{
	double interval = 0;
	clock_t start, end;

	start = clock();
	/* Code under Test */
	for (int j = 0; j < nrun; j++) {
		(*search_algorithm)(arr, arr_size, val);
	}
	/* End of Code under Test */
	end = clock();
	interval = (double)(end - start) / (double)(nrun) / (double) CLOCKS_PER_SEC * 1000000.0;
    return interval; // in microseconds (mcs)
}

int *generate_data(int *arr, int arr_size, int step) {
	for (int i = 0; i < arr_size; i=i+step){
		arr[i] = i;
	}
	return arr;
}
