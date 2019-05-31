#include <stdio.h>


void shellsort(int *a, int n) {

	int temp, j;
	int interval = n / 2;
	int k;
	while (interval >= 1) {

		
		for (int i = 0; i < interval; i++) {
			for (j = i + interval; j <= n-1; j = j + interval) {
				temp = a[j];
				for ( k = j - interval; k >= i; ) {
					
					if (temp < a[k]) {
						a[k + interval] = a[k];
						k = k - interval;
					}
					else {
						break;
					}
					
					
				
				}
				a[k + interval] = temp;
			}
		}

		interval /= 2;
	}

	

}
void print(int *a) {

	for (int i = 0; i < 8; i++) {

		printf("a[%d] = %d\n", i, *(a + i));
	}
}

int main(void) {


	int a[8] = { 3,5,1,2,6 ,4 ,8,7};
	int key = 8;

	shellsort(a, key);
	print(a);
	return 0;
}