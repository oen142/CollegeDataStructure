#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct StackNode {
	element data;
	struct StackNode *link;
}StackNode;

StackNode * top;



int isEmpty() {
	if (top == NULL) {
		return 1;
	}
	else {
		return 0;
	}

}
void push(element data) {
	StackNode *temp =(StackNode *)malloc(sizeof(StackNode));

	temp->data = data;
	temp->link = top;
	top = temp;
	

}
element pop() {
	if (isEmpty == 1) {
		printf("비었습니다.");
		return 0;
	}
	else {
		StackNode *p = top;
		element item;
		
		item = p->data;
		top = p->link;
		free(p);
		return item;
	}

}
void pirntStack() {
	StackNode *p = top;
	printf("\n STACK[");
	while (p != NULL) {
		printf("%d", p->data);
		if (p->link != NULL) {
			printf(",");
		}
		p = p->link;
	}

	printf("]");
}


int main(void) {

	
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	pirntStack();
	return 0;
}