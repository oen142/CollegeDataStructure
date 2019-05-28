#include <stdio.h>
#include <malloc.h>

typedef char element;
typedef struct DeqNode {
	element a;
	struct DeqNode *llink;
	struct DeqNode *rlink;

}DeqNode;

typedef struct {
	DeqNode *front;
	DeqNode *rear;
}Deqwc;

Deqwc *createNode() {
	Deqwc *p;
	p = (Deqwc *)malloc(sizeof(Deqwc));
	p->front = NULL;
	p->rear = NULL;

	return p;
}

int isEmpty(Deqwc *p) {
	if (p->front == NULL) {
		return 1;
	}
	else {
		return 0;
	}

}

void insertFront(Deqwc *p , element c) {
	DeqNode *ac = (DeqNode *)malloc(sizeof(DeqNode));
	ac->a = c;

	if (p->front == NULL) {
		p->front = ac;
		p->rear = ac;
		ac->llink = NULL;
		ac->rlink = NULL;

	}
	else {
		//ac->llink = NULL;
		//ac->rlink = p->front;
		//p->front = ac;

		p->front->llink = ac;
		ac->rlink = p->front;
		ac->llink = NULL;
		p->front = ac;

	}

	

}


void insertRear(Deqwc *p, element c) {
	DeqNode *ac = (DeqNode *)malloc(sizeof(DeqNode));
	ac->a = c;

	if (p->rear == NULL) {
		p->front = ac;
		p->rear = ac;
		ac->llink = NULL;
		ac->rlink = NULL;
	}
	else {
		//ac->rlink = NULL;
		//ac->llink = p->rear;
		//p->rear = ac;


		p->rear->rlink = ac;
		ac->llink = p->rear;
		ac->rlink = NULL;
		p->rear = ac;
	}

	

}

element deleteFront(Deqwc *p) {


	DeqNode *ac = p->front;
	element c;
	if(isEmpty(p)) {
		return 0;

	}else {
		c = ac->a;
		if (p->front == p->rear) {

			free(ac);
			p->front = NULL;
			p->rear = NULL;
			return c;
		}
		else if (p->front != p->rear) {
			p->front->llink = NULL;
			p->front = p->front->rlink;
			free(ac);
			p->front = NULL;
			return c;

		}


		
	}

}
element deleteRear(Deqwc *p) {


	DeqNode *ac = p->front;
	element c;
	if (isEmpty(p)) {
		return 0;

	}
	else {
		c = ac->a;
		if (p->front== p->rear) {
			free(ac);
			p->front = NULL;
			p->rear = NULL;
			return c;
		
		}
		else if (p->front != p->rear) {
			p->rear->rlink = NULL;
			p->rear = p->rear->llink;
			free(ac);
			return c;

		}



	}

}
void printDeq(Deqwc *q) {
	DeqNode *p = q->front;
	int i = 1;
	while (p) {
		printf("%d ¹øÂ° %c\n", i , p->a);
		p = p->rlink;
		i++;
	}
}

int main(void) {

	Deqwc *c =createNode();
	insertFront(c, 'a');
	insertFront(c, 'b');
	insertFront(c, 'c');
	insertFront(c, 'd');
	printDeq(c);
	printf("%c", deleteFront(c));
	printDeq(c);
//	printf("%c", deleteFront(c));
//	printDeq(c);


//	insertRear(c, 'e');
//	insertRear(c, 'f');
//	insertRear(c, 'g');
	
	return 0;
}