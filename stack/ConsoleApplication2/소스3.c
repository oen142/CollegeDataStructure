#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 20
typedef char element;

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
		printf("빈곳임\n");
		return 0;
	}
	else {
		return stack[top--];
	}
}
void printStack() {
	for (int i = 0; i <= top; i++) {
		printf("%c\n", stack[i]);
	}
}
void push(element x) {

	if (isFull()) {
		printf("꽉참");
		return;
	}
	else {
		stack[++top] = x;
		return;
	}

}
void correct(char *arr) {

	for (int i = 0; i < 19; i++) {

		switch (arr[i]) {
		case '<':
			push(arr[i]);
			break;
		case '[':
			push(arr[i]);
			break;
		case '{':
			push(arr[i]);
			break;
		case '(':
			push(arr[i]);
			break;
		case '>':
			if (pop(arr[i]) != '<') {
				printf("수식 괄호안맞음;;");
				return;
			}
			else {
				break;
			}
		case ']':
			if (pop(arr[i]) != '[') {
				printf("수식 괄호안맞음;;");
				return;
			}
			else {
				break;
			}
		case ')':

			if (pop(arr[i]) != '(') {
				printf("수식 괄호안맞음;;");
				return;
			}
			else {
				break;
			}
		case '}':
			if (pop(arr[i]) != '{') {
				printf("수식 괄호안맞음;;");
				return;
			}
			else {
				break;
			}
		}
	}
	printf("완벽한 수식입니다.");

}
int main(void) {
	char arr[] = "(a+b})({b-c){ddd}{d}";

	correct(arr);

	printStack();

	return 0;
}