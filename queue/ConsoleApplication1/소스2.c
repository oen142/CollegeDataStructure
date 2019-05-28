#include <stdio.h>
#include <stdlib.h>
#define Q 3

int front, rear;
int *createQueue() {
	int *a = (int *)malloc(sizeof(int)*Q);
	front = -1;
	rear = -1;
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
	if (rear == Q - 1) {
		return 1;
	}
	else {
		return 0;
	}
}
void enQueue(int *a, int ba) {
	if (isFull()) {
		printf("²ËÂü");
		return;
	}
	else {

		rear++;
		a[rear] = ba;
	}

}
void deQueue(int * a) {
	if (isEmpty()) {
		printf("ºö");
		return;
	}
	else {
		front++;
		a[front] = 0;
	}
}

void peek(int *a) {
	if (isEmpty()) {
		printf("ºö");
		return;
	}
	else {
		printf("%d\n", a[front + 1]);
		return;
	}
}
void printQueue(int *a) {
	if (isEmpty()) {
		printf("ºö");
		return;
	}
	else {
		for (int i = 0; i < rear + 1; i++) {
			printf("%d\n", a[i]);
		}
		return;
	}
}
int main(void) {

	int *a = createQueue();
	deQueue(a);
	enQueue(a, 1);
	enQueue(a, 2);
	enQueue(a, 3);

	printQueue(a);
	enQueue(a, 4);
	peek(a);
	deQueue(a);

	printQueue(a);
	peek(a);

	deQueue(a);
	peek(a);
	return 0;
}