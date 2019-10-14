#include "sort.h"

int* bubble_sort(int* sort, int size) {
	int* to_sort = sort;
	int sorted = 0;
	int temp;
	while (sorted == 0) {
		sorted = 1;
		int i;
		for(i = 1; i < size; i+=1) {
			if (to_sort[i] < to_sort[i-1]) {
				sorted = 0;
				temp = to_sort[i];
				to_sort[i] = to_sort[i-1];
				to_sort[i-1] = temp;
			}	
		}
	}
	return sort;
}

int* selection_sort(int* to_sort, int size) {
	int left;
	int right;
	int min;
	int temp;
	for (left = 0; left < size - 1; left+=1) {
		min = left;
		for (right = left + 1; right < size; right+=1) {
			if (to_sort[right] < to_sort[min])
				min = right;
		}
		temp = to_sort[left];
		to_sort[left] = to_sort[min];
		to_sort[min] = temp;
	}
	return to_sort;
}

