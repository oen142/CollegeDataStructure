#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 20
typedef int element;

element stack[STACK_SIZE];
int top = -1;

int isFull() {
	if (top == STACK_SIZE - 1) {
		return 1;

	}
	else {
		return 0;
	}
}
int isEmpty() {
	if (top == -1) {
	
		return 1;
	}
	else {
		return 0;
	}
}
element pop() {

	if (isEmpty() == 1) {
		printf("ºó°÷ÀÓ\n");
		return 0;
	}else {
		return stack[top--];
	}
}
void printStack() {
	for (int i = 0; i <= top; i++) {
		printf("%d\n", stack[i]);
	}
}
void push(element x) {

	if (isFull()) {
		printf("²ËÂü");
		return ;
	}	else {
		stack[++top] = x;
		return;
	}

}
int main(void) {

	push(3);
	push(2);
	printStack();
	printf("\n%d", pop());
	//
	printf("\n%d", pop());
	//
	int a = pop();
	printf("\n%d",a);
	printf("\n%d", stack[-1]);
	return 0;
}