#include <stdio.h>
#define MAX_SIZE 100
#include <stdlib.h>

typedef struct {
	int heap[MAX_SIZE];
	int heap_szie;


}heapType;

heapType* create_a_heap() {

	heapType *h = (heapType*)malloc(sizeof(heapType));
	h->heap_szie = 0;
	return h;

}
//void insert_a_heap(heapType *h , int a) {
//	int size;
//
//	h->heap_szie++;
//	if (h->heap_szie == 1) {
//		h->heap[h->heap_szie] = a;
//	}
//	else {
//
//		size = h->heap_szie;
//
//		while (size != 1 ) {
//			if (a>h->heap[size /2]) {
//				 h->heap[size]= h->heap[size/2] ;
//				size = size / 2;
//
//			}
//			
//			h->heap[size] = a;
//
//		}
//
//	}
//
//	
//}
	
void insertHeap(heapType *h, int item) {
	int i;
	h->heap_szie = h->heap_szie + 1;
	i = h->heap_szie;
	while ((i != 1) && (item < h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;

	}
	h->heap[i] = item;
}
void printheap(heapType *h) {

	for (int i = 1; i <= h->heap_szie; i++) {
		printf("[%d]  ", h->heap[i]);
	}
}
int peekheap(heapType *h) {

	int bsize = h->heap_szie;
	int b = h->heap[1];
	int parant = 1;
	int child = 2;
	int t = h->heap[h->heap_szie];

	if (h->heap_szie == 1) {
		h->heap_szie--;
		return h->heap[h->heap_szie+1];
	}

	else if (h->heap_szie > 1) {
		h->heap_szie = h->heap_szie-1;
		
		while (child <= h->heap_szie) {
			if ((child < h->heap_szie)&& (h->heap[child] < h->heap[child+1])) {
				child++;
			}
			if (t <= h->heap[child]) {
				break;
			}
			else {
				h->heap[parant] = h->heap[child];
				parant = child;
				child = child * 2;
			}
		}
		h->heap[1] = t;
		
		return b;
	}
	
	

}


int main(void) {

	heapType *h = create_a_heap();

	
	insertHeap(h, 15);
	insertHeap(h, 11);
	insertHeap(h, 9);
	insertHeap(h, 7);
	insertHeap(h, 5);
	insertHeap(h, 3);
	insertHeap(h, 1);
	printheap(h);
	printf("배열%d ", h->heap[1]);
	printf("배열%d ", h->heap[2]);
	printf("배열%d ", h->heap[3]);
	printf("배열%d ", h->heap[4]);
	printf("배열%d ", h->heap[5]);


	
	printf("%d픽\n",peekheap(h));

	printheap(h);
	return 0;
}