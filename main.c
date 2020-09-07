#include <stdio.h>
#include <stdlib.h>
#include "src/search.h"
#include "src/code_timing.h"

#define SIZE 100000
#define POINTS 10
#define DATA_FILE "data/data_100k_uniform.dat"
#define NRUN 100

#define RESULT_FORMATTER "\t%3s%-14s%3s%12d%3s%12.4f%3s\n"

int main(void) {
	int benchmark_data[SIZE] = {0};
	int check_points[POINTS] = {0};

	double linear_results[POINTS] = {0};
	double binary_results[POINTS] = {0};
	double interpolation_results[POINTS] = {0};
	double jump_results[POINTS] = {0};

	int readtmp = 0;
	short readFlag;

	// Benchmark Data Array
	FILE *fptr = fopen(DATA_FILE, "r");
	if (fptr == NULL) {
		printf("Data file %s can not be opened.\n", DATA_FILE);
		exit(EXIT_FAILURE);
	}
	else {
		for (int i = 0; i < SIZE; i++) {
			readFlag = fscanf(fptr, "%d", &readtmp);
			if (readFlag == 1) {
				benchmark_data[i] = readtmp;
			}
			else {
				printf("Unable to read the data from %s ", DATA_FILE);
				printf("at benchmark array index %d.\n", i);
				exit(EXIT_FAILURE);
			}
		}
	}

	char table_line[80] = "------------------------------------------------------------------";

	printf("\n Algorithms Performance Results at Check Points (Data Array Length: %d) \n", SIZE);
	printf("\t *%.*s*\n", 46, table_line);
	printf("\t%3s%-14s%3s%-12s%3s%-12s%3s\n", " | ", "Algorithm", " | ", "Check Point", " | ", "Run Time", " | ");
	printf("\t *%.*s*\n", 46, table_line);

	for (int i = 0; i < POINTS; i++) {
		check_points[i] = benchmark_data[SIZE/POINTS * i -1];

		// Linear Search
		linear_results[i] = code_timer(benchmark_data, SIZE, check_points[i], NRUN, (*linear_search) );
		printf(RESULT_FORMATTER, " | ", "Linear", " | ", check_points[i], " | ",
				linear_results[i], " | ");

		// Binary Search
		binary_results[i] = code_timer(benchmark_data, SIZE, check_points[i], NRUN, (*binary_search) );
		printf(RESULT_FORMATTER, " | ", "Binary", " | ", check_points[i], " | ",
				binary_results[i], " | ");

		// Interpolation Search
		interpolation_results[i] = code_timer(benchmark_data, SIZE, check_points[i], NRUN, (*interpolation_search) );
		printf(RESULT_FORMATTER, " | ", "Interpolation", " | ", check_points[i], " | ",
				interpolation_results[i], " | ");

		// Jump Search
		jump_results[i] = code_timer(benchmark_data, SIZE, check_points[i], NRUN, (*jump_search) );
		printf(RESULT_FORMATTER, " | ", "Jump", " | ", check_points[i], " | ",
				jump_results[i], " | ");

		printf("\t *%.*s*\n", 46, table_line);
	}

	// To Do: Average Performance for each Algorithm

	return 0;
}
