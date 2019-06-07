#include <stdio.h>

void binarySearch(int a[] ,int len , int find) {
	int max = len - 1;
	
	int ser = max/2;
	while (1) {
		if (a[ser] == find) {
			printf("%d", ser);
			return;
		}else if (a[ser] > find) {
			ser = (max - ser) ;
			printf("반\n");
		}
		else if (a[ser] < find) {
			ser /= 2;
			printf("또반\n");
		}


	}

}

int main(void) {
	int a[25];
	int s = 2;
	for (int i = 0; i < 25; i++) {
		a[i] = (2 + i)*s;
	}
	for (int i = 0; i < 25; i++) {
		printf("%d\n", a[i]);
	}
	printf("찾을 숫자");
	int o;
	scanf_s("%d", &o);
	binarySearch(a,25, o);



	return 0;
}