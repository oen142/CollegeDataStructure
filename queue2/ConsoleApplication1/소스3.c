#include <stdio.h>
#include <stdlib.h>
typedef  char  element ;

typedef struct mystruct
{
	char a;
	struct mystrct * link;
}mystructing;
typedef struct Queue {
	mystructing *front;
	mystructing *rear;
}Queue;

Queue * createLinkedQueue() {
	
	Queue *p;
	p = (Queue *)malloc(sizeof(Queue));
	p->front = NULL;
	p->rear = NULL;
	return p;
}
int isEmpty(Queue *p) {

	if (p->front == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}
void enQueue(Queue *p, element c) {
	mystructing * newNode = (mystructing *)malloc(sizeof(mystructing));
	newNode->a = c;
	newNode->link = NULL;
	if (p->front == NULL) {
		p->front = newNode;
		p->rear = newNode;
	}
	else {
		p->rear->link = newNode;
		p->rear = newNode;
		
	}
}
element deQueue( Queue *c) {
	mystructing *p = c->front;
	element ol;
	if (isEmpty(c)) {
		return  0;
	}
	else {
		ol = p->a;
		c->front = c->front ->link;
		if (c->front == NULL) {
			c->rear = NULL;
		}
		free(p);
		return ol;
	}
}
void print(Queue *p) {
	mystructing *c = p->front;
	printf("ť\n");
	while (c) {
		printf("%c", c->a);
		c = c->link;
	}
	
}

int main(void) {

	Queue *p = createLinkedQueue();
	element data;

	print(p);
	enQueue(p, 'A');
	print(p);
	enQueue(p, 'B');
	print(p);
	enQueue(p, 'C');
	print(p);
	deQueue(p);
	print(p);
	deQueue(p);
	print(p);
	deQueue(p);
	print(p);
	return 0;
}