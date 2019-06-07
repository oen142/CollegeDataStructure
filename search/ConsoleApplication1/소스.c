#include <stdio.h>


int sq_Search(int *a , int start , int end , int find) {
	
	a[end + 1] = find;
	int i;
	for (i = start; a[i] != find; i++) {

	}
	if (i == end + 1) {
		return -1;
	}
	else {
		return i;
	}
	

}

int main(void) {

	int a[50];

	for (int i = 0; i < 50; i++) {
		a[i] = i;

	}
	int b;
	scanf_s("%d", &b);
	printf("%d를 찾는곳은 a[%d]에 있습니다."	, b,sq_Search(a, 0, 50, b));
	





	return 0;
}