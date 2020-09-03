#ifndef CODE_TIMING_H
#define CODE_TIMING_H

double code_timer( int *arr, int arr_size, int val, int nrun,
		int *(*search_algorithm)(int *arr, int arr_size, int val) );
int *generate_data(int *arr, int arr_size, int step);

#endif
