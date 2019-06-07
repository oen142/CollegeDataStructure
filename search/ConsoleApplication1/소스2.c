#include <stdio.h>
#define INDEX_SIZE 5

typedef struct {
	int key;
	int index;


}ITE;
ITE itable[INDEX_SIZE];

void sq_Search(int *a, int start, int end, int find) {
	int i;
	int s;
	while (a[start] < find || a[end] > find) {
		s = ((double)(find - a[start])*(end - start) /
			(a[end] - a[start])) + start;


		if (a[s] == find) {
			printf("%d", s+1);
			return ;
		}
		else if(a[s] < find) {
			end= s - 1;
		}
		else if(a[s]>find) {
			start = s + 1;
		}

		
	}
	
	printf("못찾겠습니다");
	

}
void makeTable(int a[],  int size) {
	int i, n;
	n = size / INDEX_SIZE;
	if (size%INDEX_SIZE > 0) {
		n = n + 1;

	}
	for (i = 0; i < INDEX_SIZE; i++) {
		itable[i].index = i*n;
		itable[i].key = a[i*n];
	}


}
int indexSearch(int a[] , int  n , int key) {

	int i, start, end;
	if (key < a[0] || key>a[n - 1]) {
		printf("검색실패");
	}
	for (i = 0; i < INDEX_SIZE; i++) {
		if ((itable[i].key <= key) && (itable[i + 1].key > key)) {
			start = itable[i].index;
			end = itable[i + 1].index;
			break;
		}
		if (i == INDEX_SIZE) {
			start = itable[i - 1].index;
			end = n;
		}
	}

	sq_Search(a, start, end, key);

}

int main(void) {
	
	int a[25];
	int num = 25;
	int b = 2;
	for (int i = 0; i < 25; i++) {
		a[i] = (b++) * 2;
		printf("%d\n", a[i]);
	}
	makeTable(a, num);
	indexSearch(a, num, 16);
	


	return 0;
}