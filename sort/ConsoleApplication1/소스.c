#include <stdio.h>


void insertsort(int *a, int n) {

	int temp , j;
	for (int i = 1; i < n; i++) {
		 temp = a[i];
	
		for (j = i;  j > 0 ;j--) {
			if (a[j-1] > temp) {
				a[j] = a[j - 1];
			}
			else {
				break;
			}

			
		}
		a[j] = temp;

	}


}
void print(int *a) {

	for (int i = 0; i < 6; i++) {

		printf("a[%d] = %d\n", i, *(a + i));
	}
}

int main(void) {


	int a[6] = { 3,5,1,2,6 ,4};
	int key = 6;

	insertsort(a , key);
	print(a);
	return 0;
}