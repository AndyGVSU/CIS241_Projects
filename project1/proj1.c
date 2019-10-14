#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int* array, int size) {
	
	printf("\nHere is the sorted array in ascending order:");
	int count = 0;
	int max_col = 5;
	while (count != size) {
		if (count % max_col == 0)
			printf("\n");
		printf("%10d    ",array[count]);
		count++;		
	}
}

void generate_random(int* array, int array_size) {
	//10-digit numbers
	int i;
	for (i = 0; i < array_size; i+=1)
		array[i] = rand();
}

int main(int argc, char** argv) {

	int array_size;
	printf("Please input the size of the array: ");
	scanf("%d", &array_size);
	
	if (array_size < 1) {
		printf("Error: array too small");
		return 1;
	}

	clock_t start, end;
	double cpu_time_used[4];

	int bubble[array_size];
	generate_random(bubble, array_size);

	//bubble average
	start = clock();	
	//bubble_sort takes a pointer - the random ints must be copied later
	int* bubble_avg = bubble_sort(bubble, array_size);
	end = clock();
	cpu_time_used[0] = ((double) (end - start) / CLOCKS_PER_SEC) * 1000.0;
	//bubble best-case
	start = clock();
	int* bubble_best = bubble_sort(bubble_avg, array_size);
	end = clock();
	cpu_time_used[1] = ((double) (end - start) / CLOCKS_PER_SEC) * 1000.0;

	if (array_size <= 50)
		print_array(bubble_best,array_size);
	
	printf("\nArray_Size |  Algorithm | Average | Best-Case");
	printf("\n  %8d       %s    %.3f     %.3f    ",
		array_size, "Bubble", cpu_time_used[0], cpu_time_used[1]);

	int selection[array_size];
	generate_random(selection, array_size);

	//bubble average
	start = clock();	
	//bubble_sort takes a pointer - the random ints must be copied later
	int* select_avg = selection_sort(selection, array_size);
	end = clock();
	cpu_time_used[2] = ((double) (end - start) / CLOCKS_PER_SEC) * 1000.0;
	//bubble best-case
	start = clock();
	int* select_best = selection_sort(select_avg, array_size);
	end = clock();
	cpu_time_used[3] = ((double) (end - start) / CLOCKS_PER_SEC) * 1000.0;

	if (array_size <= 50)
		print_array(select_best,array_size);
	
	printf("\nArray_Size |  Algorithm | Average | Best-Case");
	printf("\n  %8d    %s    %.3f     %.3f    ",
		array_size, "Selection", cpu_time_used[2], cpu_time_used[3]);
	
	printf("\n");

	return 0;
}
