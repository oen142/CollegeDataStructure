#include <stdio.h>

typedef int ele;
int size;

void sort(int *arr, int size) {
	int min=arr[0];
	ele temp;
	int c;
	int s = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < size - 1; i++) {
		min = i;
		for (j = i + 1; j < size; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
		
		
	}
		
}
int main(void) {

	ele arr[5] = { 2,12,5,1,9 };
	size = 5;
	
	sort(arr, 5);
	for (int i = 0; i < 5; i++) {
		printf("[%d]", arr[i]);
	}

	return 0;
}