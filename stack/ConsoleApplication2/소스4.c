#include <stdio.h>
#include <stdlib.h>
typedef char element;
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
	StackNode *temp = (StackNode *)malloc(sizeof(StackNode));

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
		printf("%c", p->data);
		if (p->link != NULL) {
			printf(",");
		}
		p = p->link;
	}

	printf("]");
}

void isCorrect(char *arr) {
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

	char arr[] = "[(a+b)]-(C}-d){3}";

	isCorrect(arr);
	return 0;
}