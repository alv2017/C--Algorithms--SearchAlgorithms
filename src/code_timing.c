#include <stdio.h>
#include <stdlib.h>
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

double average_runtime(double *runtimes_arr, int arr_size) {
	double avg = 0;
	for (int i = 0; i < arr_size; i++) {
		avg += runtimes_arr[i];
	}

	if (arr_size > 0)
	    return avg / (double) arr_size;
	else
		exit(EXIT_FAILURE);
}



