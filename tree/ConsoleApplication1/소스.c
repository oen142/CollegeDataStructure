#include <stdio.h>
#include <stdlib.h>



typedef struct treeNode {

	char number;
	struct treeNode *lchild;
	struct treeNode *rchild;

}treeNode;


treeNode *createNode(char data,treeNode *lNode , treeNode *rNode ) {
	treeNode *p = (treeNode *)malloc(sizeof(treeNode));
	p->number = data;
	
	p->lchild = lNode;
	
	p->rchild = rNode;
	return p;

}

void before(treeNode *root) {
	treeNode *p = root;
	if(p!=NULL){
		printf("%c", p->number);
		before(p->lchild);
		before(p->rchild);
	}
	

}
void middle(treeNode *root) {
	treeNode *p = root;
	if (p != NULL) {
		middle(p->lchild);
		printf("%c", p->number);
		middle(p->rchild);
	}
}
void after(treeNode *root) {
	treeNode *p = root;
	if (p != NULL) {
		after(p->lchild);
		after(p->rchild);
		printf("%c", p->number);
	}
}
int main(void) {

	treeNode *n7 = createNode('d', NULL ,NULL );
	treeNode *n6 = createNode('c' , NULL , NULL);
	treeNode *n5 = createNode('b', NULL, NULL);
	treeNode *n4 = createNode('a', NULL, NULL);
	treeNode *n3 = createNode('/' , n6 , n7);
	treeNode *n2 = createNode('*' , n4 , n5);
	treeNode *n1 = createNode('-' , n2 ,n3);

	before(n1);
	printf("\n");
	middle(n1);
	printf("\n");
	after(n1);

	return 0;
}