#include <stdio.h>
#include <stdlib.h>
#include "src/search.h"
#include "src/code_timing.h"

#define SIZE 100000
#define POINTS 10
#define DATA_FILE "data/data_100k_uniform.dat"
#define NRUN 100

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

	// Algorithms Performance at Check Points

	const char RESULT_FORMATTER[] = "\t%3s%-14s%3s%12d%3s%12.4f%3s\n";
	const char HEADER_FORMATTER[] = "\t%3s%-14s%3s%12s%3s%12s%3s\n";
	const char TABLE_LINE[80] = "------------------------------------------------------------------";

	// Table Header
	printf("\n Search Algorithms Performance Results at Check Points (On Uniform Data Array of Length %d) \n", SIZE);
	printf("\t *%.*s*\n", 46, TABLE_LINE);
	printf(HEADER_FORMATTER, " | ", "Algorithm", " | ", "Check Point", " | ", "Run Time,mcs", " | ");
	printf("\t *%.*s*\n", 46, TABLE_LINE);

	// Results
	for (int i = 0; i < POINTS; i++) {
		check_points[i] = benchmark_data[SIZE/POINTS * i -1];

		// Linear Search
		linear_results[i] = code_timer(benchmark_data, SIZE, check_points[i], NRUN, linear_search );
		printf(RESULT_FORMATTER, " | ", "Linear", " | ", check_points[i], " | ",
				linear_results[i], " | ");

		// Binary Search
		binary_results[i] = code_timer(benchmark_data, SIZE, check_points[i], NRUN, binary_search );
		printf(RESULT_FORMATTER, " | ", "Binary", " | ", check_points[i], " | ",
				binary_results[i], " | ");

		// Interpolation Search
		interpolation_results[i] = code_timer(benchmark_data, SIZE, check_points[i], NRUN, interpolation_search );
		printf(RESULT_FORMATTER, " | ", "Interpolation", " | ", check_points[i], " | ",
				interpolation_results[i], " | ");

		// Jump Search
		jump_results[i] = code_timer(benchmark_data, SIZE, check_points[i], NRUN, jump_search );
		printf(RESULT_FORMATTER, " | ", "Jump", " | ", check_points[i], " | ",
				jump_results[i], " | ");

		printf("\t *%.*s*\n", 46, TABLE_LINE);
	}

	// Algorithms Average Performance
	double linear_avg = average_runtime(linear_results, POINTS);
	double binary_avg = average_runtime(binary_results, POINTS);
	double interpolation_avg = average_runtime(interpolation_results, POINTS);
	double jump_avg = average_runtime(jump_results, POINTS);

	// Table Header
	printf("\n Search Algorithms Average Performance Results (On Uniform Data Array of Length %d) \n", SIZE);
	printf("\t *%.*s*\n", 31, TABLE_LINE);
	printf("\t%3s%-14s%3s%12s%3s\n", " | ", "Algorithm", " | ", "Run Time,mcs", " | ");
	printf("\t *%.*s*\n", 31, TABLE_LINE);

	// Results
	printf("\t%3s%-14s%3s%12.4f%3s\n", " | ", "Linear", " | ", linear_avg, " | ");
	printf("\t%3s%-14s%3s%12.4f%3s\n", " | ", "Binary", " | ", binary_avg, " | ");
	printf("\t%3s%-14s%3s%12.4f%3s\n", " | ", "Interpolation", " | ", interpolation_avg, " | ");
	printf("\t%3s%-14s%3s%12.4f%3s\n", " | ", "Jump", " | ", jump_avg, " | ");

	printf("\t *%.*s*\n", 31, TABLE_LINE);

	return 0;
}
