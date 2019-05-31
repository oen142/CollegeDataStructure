#include <stdio.h>

int sort[30];

void merge(int *a, int m, int middle, int n) {

	int i, j, k, t;
	i = m;
	j = middle + 1;
	k = m;
	while (i <= middle && j <= n) {
		if (a[i] <= a[j]) {
			sort[k] = a[i];
			i++;
		}
		else {
			sort[k] = a[j];
			j++;
		}
		k++;
	}
	if (i > middle) {
		for (t = j; t  <= n; t++, k++) {
			sort[k] = a[t];

		}
	}
	else {
		for (t = i; t <= middle; t++, k++) {
			sort[k] = a[t];

		}
	}

	for (t = m;  t <= n; t++) {
		a[t] = sort[t];
	}
	printf("\n병합정렬");
	for(t = 0; t < 8; t++) {
		printf("%4d", a[t]);
	}
	

}
void mergeSort(int *a, int m, int n) {

	int middle;
	if (m<n) {
		middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle+1, n);
		merge(a, m, middle, n);

	}

}

int main(void) {

	int a[8] = { 1,10,2,3,5,9,6,8 };

	mergeSort(a, 0, 7);


	return 0;
}