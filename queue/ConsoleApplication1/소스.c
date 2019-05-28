#include <stdio.h>
#include <stdlib.h>
#define Q 4

int front=-1, rear =-1;
int *createQueue() {
	int *a = (int *)malloc(sizeof(int)*Q);
	front = 0;
	rear = 0;
}
int isEmpty() {
	if (rear == front) {
		return 1;

	}
	else {
		return 0;
	}
}
int isFull() {
	if ((rear+1)%Q == front) {
		printf("²ËÂü");
		return 1;
	}
	else {
		return 0;
	}
}
void enQueue( int *a , int ba) {
	if (isFull()) {
		return;
	}
	else {
		
		rear++;

		a[rear%Q] = ba;
	}

}
void deQueue(int * a) {
	if (isEmpty()) {
		printf("ºö");
		return;
	}
	else {
		front++;
		a[front%Q] = 0;
	}
}

void peek(int *a) {
	if (isEmpty()) {
		printf("ºö");
		return;
	}
	else {
		printf("%d\n", a[(front +1)%Q]);
		return;
	}
}
void printQueue(int *a) {
	if (isEmpty()) {
		printf("ºö");
		return;
	}
	else {
	
		int first = (front + 1) % Q;
		int last = (rear + 1) % Q;
		int i = first;
		while (i != last) {
			printf("%d", a[i]);
			i = (i + 1) % Q;
		}
		return;
	}
}
int main(void) {

	int *a = createQueue();

	enQueue(a, 1);
	enQueue(a, 2); 
	enQueue(a, 1);
	
	enQueue(a, 1);
	printQueue(a);

	deQueue(a);
	printQueue(a);


	return 0;
}