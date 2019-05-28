#include <stdio.h>

typedef int ele;
int size;

void sort(int *arr, int size) {
	int temp;
	for (int i = size-1; i > 0 ; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}

			for (int k = 0; k < 5; k++) {
				printf("[%d]", arr[k]);
			}
			printf("\n");
		}

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